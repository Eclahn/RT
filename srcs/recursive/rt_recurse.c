/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_recurse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 22:35:21 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/29 07:47:32 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		this_recurse(t_list *elem, t_thread *data)
{
	t_recursive *tmp;
	t_float3	color;

	tmp = (t_recursive *)elem->content;
	color = rt_recurse_pixel((t_recursive *)elem->content,
			&data->win->scene, data->thread);
	rt_float3_add(&color, tmp->color, tmp->color);
	color = *tmp->color;
	fix_color(&color.x, &color.y, &color.z);
	*(*(t_recursive *)elem->content).pixel = SDL_MapRGBA(data->win->pix,
											(int)(color.x * 255),
											(int)(color.y * 255),
											(int)(color.z * 255),
														0xff);
}

int				rt_recurse(void *data)
{
	int			thread;
	t_list		*elem;

	thread = ((t_thread*)data)->thread;
	rt_scene_pixels(((t_thread*)data)->win, thread, ((t_thread*)data)->screen);
	elem = rt_get_queue(thread);
	while (elem)
	{
		if ((*(t_recursive *)elem->content).iter < NUM_ITER)
			this_recurse(elem, (t_thread*)data);
		rt_add_pool(elem, thread);
		elem = rt_get_queue(thread);
	}
	return (0);
}
