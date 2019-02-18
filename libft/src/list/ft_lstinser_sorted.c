/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinser_sorted.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 18:47:10 by juthomas          #+#    #+#             */
/*   Updated: 2016/09/02 01:28:30 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstinser_sorted(t_list **lst, t_list *elem,
		int (*f)(t_list *lst, t_list *elem))
{
	if (*lst && *lst != elem && f(*lst, elem))
		return (ft_lstinser_sorted(&((*lst)->next), elem, f));
	if (elem && elem != *lst)
		elem->next = *lst;
	*lst = elem;
	return (0);
}
