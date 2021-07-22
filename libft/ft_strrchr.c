/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 16:38:32 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/04/09 16:38:39 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*save;
	char	ch;

	ch = c;
	save = NULL;
	if (c == '\0')
	{	
		s = s + ft_strlen((char *)s);
		return ((char *)s);
	}
	while (*s)
	{
		if (*s == ch)
			save = (char *)s;
		s++;
	}
	return (save);
}
