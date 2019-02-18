/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_add_pool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 09:22:48 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/25 19:31:35 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_add_pool(t_list *elem, int thread)
{
	t_list **start;
	t_list **end;

	elem->next = NULL;
	end = rt_list_pool(1, thread);
	if (!(*end))
	{
		start = rt_list_pool(0, thread);
		*start = elem;
	}
	else
		(*end)->next = elem;
	*end = elem;
}
