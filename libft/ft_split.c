/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 14:34:57 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/04/16 14:34:59 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_rows(const char *s, char c)
{
	int	rows;
	int	i;

	i = 0;
	rows = 0;
	while (s[i])
	{
		if ((s[i] == c && s[i + 1] != c) || s[i + 1] == '\0')
			rows++;
		i++;
	}
	return (rows);
}

char	**ft_split(char const *s, char c)
{
	int		rows;
	char	**ptr;
	int		start;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	ptr = malloc((ft_rows(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	rows = 0;
	while (i < (int)ft_strlen(s))
	{
		if (s[i] != c && s[i])
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			ptr[rows++] = ft_substr(s, start, (i - start));
		}
		i++;
	}
	ptr[rows++] = (NULL);
	return (ptr);
}
