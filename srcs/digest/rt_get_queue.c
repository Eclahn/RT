/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_get_queue.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 21:55:38 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/28 16:40:15 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_list	*rt_get_queue(int thread)
{
	t_list **start;
	t_list *elem;

	start = rt_list_queue(0, thread);
	elem = *start;
	if (*start)
		*start = (*start)->next;
	if (*start == NULL)
	{
		start = rt_list_queue(1, thread);
		*start = NULL;
	}
	return (elem);
}
