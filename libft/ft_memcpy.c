/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:24:56 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/04/07 13:24:57 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*destino;
	const char		*source;
	int				i;

	i = 0;
	destino = dst;
	source = src;
	if (!dst && !src)
		return (0);
	while (n-- > 0)
	{
		destino[i] = source[i];
		i++;
	}
	return (dst);
}
