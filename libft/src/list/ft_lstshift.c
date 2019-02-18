/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstshift.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:47:41 by juthomas          #+#    #+#             */
/*   Updated: 2015/12/07 18:59:51 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstshift(t_list **lst)
{
	t_list	*rslt;

	rslt = *lst;
	if (*lst)
	{
		*lst = (*lst)->next;
		rslt->next = NULL;
	}
	return (rslt);
}
