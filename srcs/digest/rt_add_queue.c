/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_add_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 21:59:40 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/27 01:46:42 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_add_queue(t_recursive *data, int thread)
{
	t_list **start;
	t_list **end;
	t_list *elem;

	elem = rt_get_pool(thread);
	if (elem)
		ft_memcpy(elem->content, data, elem->content_size);
	else
		elem = ft_lstnew(data, sizeof(t_recursive));
	if (!elem)
		exit(0);
	end = rt_list_queue(1, thread);
	if (!(*end))
	{
		start = rt_list_queue(0, thread);
		*start = elem;
	}
	else
		(*end)->next = elem;
	*end = elem;
}
