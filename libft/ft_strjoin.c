/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 13:33:11 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/04/29 18:05:47 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		s1len;

	if (!s1 || !s2)
		return (NULL);
	ptr = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	s1len = ft_strlen((char *)s1);
	if (ptr)
	{
		ft_memcpy(ptr, s1, s1len);
		ft_memcpy(ptr + s1len, s2, ft_strlen((char *)s2) + 1);
	}
	return (ptr);
}
