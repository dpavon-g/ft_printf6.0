#include "libftprintf.h"

void	showString(int *length, char *string)
{
	int i;
	
	i = 0;
	while (string[i])
	{
		ft_putchar_fd(string[i], 1);
		(*length)++;
		i++;
	}
}

int	ft_lenFinal(unsigned long num, int base)
{
	int i;

	i = 0;
	if (num == 0)
	{
		i++;
		return (i);
	}
	while (num > 0)
	{
		i++;
		num /= base;
	}
	return (i);
}

char	*ft_transformNumber(unsigned long num, int type, int base)
{
	int		len;
	char 	*number;
	char 	*string;

	number = NULL;
	if (type == 0)
		string = ft_strdup("0123456789ABCDEF");
	else
		string = ft_strdup("0123456789abcdef");
	len = ft_lenFinal(num, base);
	number = (char *)malloc(sizeof(char) * len + 1);
	number[len] = '\0';
	len--;
	while (len >= 0)
	{
		number[len] = string[num % base];
		num /= base;
		len--;
	}
	free(string);
	return (number);
}

int	strSpaces2(int *length, t_printf *content, char *str, int len)
{
	int		position;
	char	value;
	
	position = 0;
	if (content->zero == 1 && content->less == 0)
	{
		value = '0';
		if (str[0] == '-')
		{
			ft_putchar_fd('-', 1);
			(*length)++;
			position++;
		}
	}
	else
		value = ' ';
	while (content->width > len && content->width > content->precision)
	{
		ft_putchar_fd(value, 1);
		content->width--;
		(*length)++;
	}
	return (position);
}

int	strSpaces(int *length, t_printf *content, char *str)
{
	int		len;
	int		position;

	position = 0;
	len = (int)ft_strlen(str);
	if (content->precision != -1)
	{
		if (str[0] == '-' && content->precision >= len)
			content->width--;
		while (content->width > len && content->width > content->precision)
		{
			ft_putchar_fd(' ', 1);
			content->width--;
			(*length)++;
		}
	}
	else
		position = strSpaces2(length, content, str, len);
	return (position);
}

void	finalNumber(int *length, t_printf *content, char *str)
{
	int i;
	int len;

	i = 0;
	len = (int)ft_strlen(str);
	if (str[i] == '-')
	{
		i++;
		ft_putchar_fd('-', 1);
		(*length)++;
		len--;
	}
	while (content->precision > len)
	{
		ft_putchar_fd('0', 1);
		(*length)++;
		len++;
	}

	showString(length, &str[i]);
}

void	showNumber(int *length, int num, t_printf *content)
{
	char	*str;
	int		i;
	
	i = 0;
	if (num == 0 && content->precision == 0)
		str = ft_strdup("");
	else
		str = ft_itoa(num);
	if (content->less == 0)
	{	
		i = strSpaces(length, content, str);
		finalNumber(length, content, &str[i]);
	}
	else
	{
		finalNumber(length, content, str);
		strSpaces(length, content, str);
	}
	free(str);
}

void	digits(int *length, va_list ap, t_printf *content)
{
	int num;

	num = va_arg(ap, int);
	if (content->haveSpace == 1)
	{
		ft_putchar_fd(' ', 1);
		(*length)++;
	}
	showNumber(length, num, content);
}

void	showSpace(t_printf *content, int *length, int len)
{
	while (content->width > len)
	{
		ft_putchar_fd(' ', 1);
		(*length)++;
		content->width--;
	}
}

void	characters(int *length, va_list ap, t_printf *content)
{
	char character;
	
	character = va_arg(ap, int);
	if (content->less == 0)
	{
		(*length)++;
		showSpace(content, length, 1);
		ft_putchar_fd(character, 1);
	}
	else
	{
		(*length)++;
		ft_putchar_fd(character, 1);
		showSpace(content, length, 1);
	}
}

void	stringSpace(int *length, t_printf *content, char *str)
{
	int len;

	len = (int)ft_strlen(str);
	if (content->precision < len && content->precision > -1)
		len = content->precision;
	while (content->width > len)
	{
		(*length)++;
		ft_putchar_fd(' ', 1);
		len++;
	}

}

void	stringPrecision(int *length, t_printf *content, char *str)
{
	int len;
	int i;

	len = content->precision;
	i = 0;
	if (content->less == 0)
		stringSpace(length, content, str);
	if (len == -1)
		showString(length, str);
	while (len > 0 && str[i])
	{
		ft_putchar_fd(str[i], 1);
		(*length)++;
		len--; 
		i++;
	}
	if (content->less == 1)
		stringSpace(length, content, str);
}

void	string(int *length, va_list ap, t_printf *content)
{
	char *str;
	
	str = ft_strdup(va_arg(ap, char*));
	if (!str)
	{
		if (content->precision > -1 && content->precision < 6)
			content->precision = 0;
		free(str);
		str = ft_strdup("(null)");
	}
	stringPrecision(length, content, str);
	free(str);
}

void	unsigNum(int *length, va_list ap, t_printf *content)
{
	unsigned int	num;
	char			*str;
	int				i;

	num = va_arg(ap, unsigned int);
	i = 0;
	if (num == 0 && content->precision == 0)
		str = ft_strdup("");
	else
		str = ft_transformNumber(num, 1, 10);
	if (content->less == 0)
	{	
		i = strSpaces(length, content, str);
		finalNumber(length, content, &str[i]);
	}
	else
	{
		finalNumber(length, content, str);
		strSpaces(length, content, str);
	}
	free(str);	
}

void	hexadecimal(int *length, va_list ap, t_printf *content, char type)
{
	unsigned int	num;
	char			*str;
	int				i;
	int				k;

	num = va_arg(ap, unsigned int);
	if (type == 'X')
		k = 0;
	else
		k = 1;
	if (num == 0 && content->precision == 0)
		str = ft_strdup("");
	else
		str = ft_transformNumber(num, k, 16);
	if (content->less == 0)
	{	
		i = strSpaces(length, content, str);
		finalNumber(length, content, &str[i]);
	}
	else
	{
		finalNumber(length, content, str);
		strSpaces(length, content, str);
	}
	free(str);
}

void	pointer(int *length, va_list ap, t_printf *content)
{
	unsigned long 	num;
	char			*aux;
	char			*string;
	int				i;

	i = 0;
	num = va_arg(ap, long);
	if (num != 0)
	{
		aux = ft_transformNumber(num, 1, 16);
		string = ft_strjoin("0x", aux);
		free(aux);
	}
	else
		string = ft_strdup("(nil)");
	if (content->less == 0)
	{	
		i = strSpaces(length, content, string);
		finalNumber(length, content, &string[i]);
	}
	else
	{
		finalNumber(length, content, string);
		strSpaces(length, content, string);
	}
	free(string);
}

void	specifyType(const char s, t_printf *content, va_list ap, int *length)
{
	if (s == 'd')
		digits(length, ap, content);
	else if (s == 'i')
		digits(length, ap, content);
	else if (s == 'c')
		characters(length, ap, content);
	else if (s == 's')
		string(length, ap, content);
	else if (s == '%')
	{
		ft_putchar_fd('%', 1);
		(*length)++;
	}
	else if (s == 'u')
		unsigNum(length, ap, content);
	else if (s == 'X' || s == 'x')
		hexadecimal(length, ap, content, s);
	else if (s == 'p')
		pointer(length, ap, content);
	// ft_isS(ap, length, content);
	// if (s == 'd' || s == 'i')
	// 	ft_isD(ap, length, content);
	// if (s == 'c')
	// 	ft_isC(ap, length, content);
	// if (s == '%')
	// {
	// 	ft_putchar_fd('%', 1);
	// 	(*length)++;
	// }
	// if (s == 'x' || s == 'X')
	// 	ft_isHexa(ap, length, content, s);
	// if (s == 'p')
	// 	ft_isPoint(ap, length, content);
	// if (s == 'u')
	// 	ft_isU(ap, length, content);
}

int	point(const char *str, t_printf *content, va_list ap)
{
	int i;

	i = 1;
	if (str[i] >= '0' && str[i] <= '9')
	{
		content->precision = ft_atoi(&str[i]);
		while (str[i] >= '0' && str[i] <= '9')
			i++;
		i--;
	}
	else if (str[i] == '*')
	{
		content->precision = va_arg(ap, int);
		if (content->precision < 0)
			content->precision = -1;
	}
	else
	{
		content->precision = 0;
		i--;
	}
	return (i);
}

int	width(const char *str, t_printf *content)
{
	int i;

	i = 0;
	if (str[i] == '0')
		content->zero = 1;
	content->width = ft_atoi(&str[i]);
	while(str[i] >= '0' && str[i] <= '9')
		i++;
	i--;
	return (i);
}

void	apostro(t_printf *content, va_list ap)
{
	content->width = va_arg(ap, int);
	if (content->width < 0)
	{
		content->width *= -1;
		content->less = 1;
	}
}

int	specifyFlag(const char *str, int *length, t_printf *content, va_list ap)
{
	int i;

	i = 0;
	while (ft_strchr(TYPES, str[i]) == 0 && str[i])
	{
		if (str[i] == ' ')
			content->haveSpace = 1;
		else if (str[i] == '.')
			i += point(&str[i], content, ap);
		else if (str[i] >= '0' && str[i] <= '9')
			i += width(&str[i], content);
		else if (str[i] == '-')
			content->less = 1;
		else if (str[i] == '*')
			apostro(content, ap);
		i++;
	}
	if (str[i] == '\0')
		return (i);
	if (ft_strchr(TYPES, str[i]) != 0)
		specifyType(str[i], content, ap, length);
	i++;
	return (i);
}

int	specify(const char *str, int *length, va_list ap)
{
	int i;
	
	t_printf content;

	ft_bzero(&content, sizeof(content));
	content.precision = -1;
	i = 0;
	i += specifyFlag(&str[i], length, &content, ap);
	return (i);
}

int	travel(va_list ap, const char *str)
{
	int i;
	int length;

	length = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != '%')
		{
			ft_putchar_fd(str[i], 1);
			length++;
			i++;
		}
		else
		{
			i++;
			i += specify(&str[i], &length, ap);
		}
	}

	return (length);
}

int	ft_printf(const char *str, ...)
{
	int total;

	total = 0;
	va_list(ap);
	va_start(ap, str);
	total += travel(ap, str);
	va_end(ap);
	return (total);
}
