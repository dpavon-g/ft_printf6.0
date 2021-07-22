/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:32:16 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/04/14 16:12:25 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long	num;
	int		valor;

	valor = 1;
	num = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			valor = valor * -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (num * valor > 2147483647)
			return (-1);
		if (num * valor < -2147483648)
			return (0);
		num = num * 10 + *str - 48;
		str++;
	}
	return (num * valor);
}
