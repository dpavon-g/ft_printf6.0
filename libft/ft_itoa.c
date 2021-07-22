/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 15:40:37 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/04/14 16:38:00 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	units(int n)
{
	int	figures;

	figures = 0;
	if (n < 0)
	{
		n = n * -1;
		figures++;
	}
	else if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		figures++;
	}
	return (figures);
}

static char	*ft_morethan(char *ptr, long n2, int figures, int *i)
{
	while (n2 > 0)
	{
		ptr[figures--] = n2 % 10 + 48;
		n2 /= 10;
		(*i)++;
	}
	return (ptr);
}

char	*ft_itoa(int n)
{
	int		i;
	long	n2;
	char	*ptr;
	int		figures;

	i = 0;
	n2 = n;
	figures = units(n2);
	ptr = malloc(figures + 1);
	if (!ptr)
		return (NULL);
	if (n2 == 0)
		ptr[i++] = '0';
	if (n2 < 0)
	{
		n2 *= -1;
		ptr[i++] = '-';
	}
	figures--;
	ft_morethan(ptr, n2, figures, &i);
	ptr[i] = '\0';
	return (ptr);
}
