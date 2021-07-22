/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:22:13 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/04/09 17:22:15 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int	i;

	i = -1;
	if (!dst && !src)
		return (0);
	if (dstsize-- == 0)
		return (ft_strlen((char *)src));
	while (dstsize > (size_t)++i && src[i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (ft_strlen((char *)src));
}
