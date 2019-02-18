/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_default_scene.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 15:21:59 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/07 18:24:35 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_default_scene(t_stock *stock)
{
	size_t		cur_scn;
	size_t		cur_obj;
	size_t		cur_cam;
	size_t		cur_lum;

	cur_scn = 0;
	while (cur_scn < stock->num_scn)
	{
		cur_obj = 0;
		cur_lum = 0;
		cur_cam = 0;
		while (cur_obj < stock->scene[cur_scn].num_obj)
			rt_default_object(&stock->scene[cur_scn].object[cur_obj++]);
		while (cur_lum < stock->scene[cur_scn].num_lum)
			rt_default_light(&stock->scene[cur_scn].light[cur_lum++]);
		while (cur_cam < stock->scene[cur_scn].num_cam)
			rt_default_camera(&stock->scene[cur_scn].cam[cur_cam++]);
		rt_default_light(&stock->scene[cur_scn].ambient);
		cur_scn++;
	}
}
