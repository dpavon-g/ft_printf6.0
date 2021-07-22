/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:24:43 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/04/07 13:24:45 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*destino;
	const unsigned char	*source;

	destino = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (n-- > 0)
	{
		*destino = *source;
		if (*source == (unsigned char)c)
			return ((void *)destino + 1);
		destino++;
		source++;
	}
	return (NULL);
}
