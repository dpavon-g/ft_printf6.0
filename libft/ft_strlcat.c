/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 12:56:15 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/03/15 12:56:19 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
	i = length of dst
	If the size to copy(dstsize) on dst is smaller than dst, return 
	automatically the length of src + the size to copy(dstsize)
	Else, if dstsize is bigger than the length of dst(i), 
	while i + 1(the null) is small than the size to copy(dstsize), and 
	the current position on the src[j] is diferent than '\0', copy it
	on the position of dst[i].
	When the while finish, put '\0' on the last space of dst[i].
	Finally return the value of dst + src + dstsize.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(dst);
	j = 0;
	if (dstsize < i)
	{
		j = ft_strlen(src);
		return (dstsize + j);
	}
	while (i + 1 < dstsize && src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	while (src[j++])
		i++;
	return (i);
}
