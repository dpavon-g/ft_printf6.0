/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:59:20 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/04/21 15:59:21 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*copy;

	copy = NULL;
	if (lst)
	{
		copy = lst;
		while (copy)
		{
			f(copy->content);
			copy = copy->next;
		}
	}
}
/*
	If lst exist copy is equal to lst, while iterate copy, applies
	the function f to the actual content of copy, after that copy is equal to
	the next pointer of copy.
*/