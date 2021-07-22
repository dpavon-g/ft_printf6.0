/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 19:14:34 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/04/20 19:14:35 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	temp = NULL;
	if (lst)
	{
		temp = *lst;
		if (!temp)
			*lst = new;
		else
		{	
			temp = ft_lstlast(*lst);
			temp->next = new;
		}
	}
}
/*
	Si lst existe temp apunta al principio de la lista.
	Si temp no existe lst apunta a new directamente 
	porque no hay más espacios de memoria.
	Si temp existe recorre temp y hace que apunte 
	al final de la lista e inserta new.
*/