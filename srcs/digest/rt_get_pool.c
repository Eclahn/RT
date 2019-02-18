/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_get_pool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 09:18:13 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/25 19:31:03 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_list	*rt_get_pool(int thread)
{
	t_list **start;
	t_list *elem;

	start = rt_list_pool(0, thread);
	elem = *start;
	if (*start)
		*start = (*start)->next;
	if (!(*start))
	{
		start = rt_list_pool(1, thread);
		*start = NULL;
	}
	if (elem)
		elem->next = NULL;
	return (elem);
}
