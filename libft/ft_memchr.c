/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:10:04 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/04/07 15:10:10 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*source;
	int			i;
	char		ch;

	i = 0;
	ch = c;
	source = s;
	while (n-- > 0)
	{
		if (source[i] == ch)
			return ((void *)source + i);
		i++;
	}
	return (NULL);
}
