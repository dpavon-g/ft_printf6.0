/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavon <pavon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 18:17:47 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/07/21 18:51:08 by pavon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	showSpaces(t_printf *content, char *str, int *length)
{
	char value;
	int len;
	int aux;

	aux = content->precision;
	if (content->zero == 0)
		value = ' ';
	else
		value = '0';
	len = (int)ft_strlen(str);
	if (content->precision > len)
	{
		aux -= len;
		len += aux;
	}
	while (content->width > len)
	{
		ft_putchar_fd(value, 1);
		len++;
		(*length)++;
	}
}

void	showPrecision(int *length, t_printf *content, char *str)
{
	int len;

	len = (int)ft_strlen(str);
	if (str[0] == '-')
		content->precision += 1;
	while (content->precision > len)
	{
		ft_putchar_fd('0', 1);
		len++;
		(*length)++;
	}
}

void	showWidth(int *length, char *string, t_printf *content)
{
	int i;

	i = 0;
	if (string[i] == '-' && (content->zero == 1 || content->precision -1))
	{
		ft_putchar_fd('-', 1);
		i++;
		(*length)++;
	}
	if (content->less == 0)
	{
		showSpaces(content, string, length);
		showPrecision(length, content, string);
		showString(length, &string[i]);
	}
	else
	{
		showPrecision(length, content, string);
		showString(length, &string[i]);
		showSpaces(content, string, length);
	}
}

void	ft_digits(int *length, va_list ap, t_printf *content)
{
	int num;
	char *string;

	num = va_arg(ap, int);
	string = ft_itoa(num);
	showWidth(length, string, content);
}

void	ft_specifyType(const char s, t_printf *content, va_list ap, int *length)
{
	if (s == 'd')
		ft_digits(length, ap, content);
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

int	ft_Point(const char *str, t_printf *content, va_list ap)
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

int	ft_width(const char *str, t_printf *content)
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

void	ft_apostro(t_printf *content, va_list ap)
{
	content->width = va_arg(ap, int);
	if (content->width < 0)
	{
		content->width *= -1;
		content->less = 1;
	}
}

int	ft_specifyFlag(const char *str, int *length, t_printf *content, va_list ap)
{
	int i;

	i = 0;
	while (ft_strchr(TYPES, str[i]) == 0 && str[i])
	{
		if (str[i] == ' ')
			content->haveSpace = 1;
		else if (str[i] == '.')
			i += ft_Point(&str[i], content, ap);
		else if (str[i] >= '0' && str[i] <= '9')
			i += ft_width(&str[i], content);
		else if (str[i] == '-')
			content->less = 1;
		else if (str[i] == '*')
			ft_apostro(content, ap);
		i++;
	}
	if (ft_strchr(TYPES, str[i]) != 0)
		ft_specifyType(str[i], content, ap, length);
	i++;
	return (i);
}

int	ft_specify(const char *str, int *length, va_list ap)
{
	int i;
	t_printf content;

	ft_bzero(&content, sizeof(content));
	content.precision = -1;
	i = 0;
	i += ft_specifyFlag(&str[i], length, &content, ap);
	return (i);
}

int	ft_travel(va_list ap, const char *str)
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
			i += ft_specify(&str[i], &length, ap);
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
	total += ft_travel(ap, str);
	va_end(ap);
	return (total);
}
