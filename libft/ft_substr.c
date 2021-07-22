/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 12:11:18 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/04/14 12:48:11 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*ptr;
	size_t		total;

	if (!s)
		return (NULL);
	i = ft_strlen((char *)s);
	if (start >= (unsigned int)i)
	{
		ptr = malloc(1);
		ptr[0] = '\0';
		return (ptr);
	}
	if (len + start > i)
		total = i - start;
	else
		total = len;
	ptr = malloc(total + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s + start, total);
	ptr[total] = '\0';
	return (ptr);
}
