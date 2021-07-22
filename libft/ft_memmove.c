/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 13:42:46 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/04/07 13:42:48 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*destino;
	const char	*source;
	char		*finald;
	const char	*finals;

	destino = dest;
	source = src;
	if (!dest && !src)
		return (0);
	if (destino < source)
	{
		while (n--)
			*destino++ = *source++;
	}
	else
	{
		finals = source + (n - 1);
		finald = destino + (n - 1);
		while (n--)
			*finald-- = *finals--;
	}
	return (dest);
}
