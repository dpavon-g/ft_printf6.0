/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 15:07:51 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/04/21 15:07:52 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*copy;

	copy = NULL;
	if (lst)
	{
		while (*lst)
		{
			copy = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = copy;
		}
	}
}
/*
	If lst contains something, while lst is not NULL.
	Copy is equal to the pointer to the next lst,
	after that use the function lstdelone
	for delete the actual lst pointer, then lst is equal
	than copy (the pointer to the next lst).
*/