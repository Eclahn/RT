/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 22:49:48 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/29 02:52:44 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	get_pos_sphere(t_float3 *impact, float *longi, float *lati)
{
	t_float3	tmp;
	t_float3	tmp2;

	tmp.x = 0;
	tmp.y = 1;
	tmp.z = 0;
	rt_vector_normalize(&tmp);
	tmp2 = *impact;
	tmp2.z = 0;
	rt_vector_normalize(&tmp2);
	*longi = impact->x < 0 ? 1.0 - rt_vector_angle(&tmp, &tmp2) / (2.0 * M_PI)
	: rt_vector_angle(&tmp, &tmp2) / (2.0 * M_PI);
	tmp.y = 0;
	tmp.z = 1;
	rt_vector_normalize(&tmp);
	tmp2 = *impact;
	rt_vector_normalize(&tmp2);
	*lati = rt_vector_angle(&tmp, &tmp2) / (M_PI);
	return ;
}

float	get_pos_cylinder(t_getpos vars, float *circular, int h, int w)
{
	float		height;
	t_float3	tmp;
	t_float3	tmp2;

	tmp.x = 0;
	tmp.y = 1;
	tmp.z = 0;
	rt_vector_normalize(&tmp);
	tmp2 = *vars.impact;
	tmp2.z = 0;
	rt_vector_normalize(&tmp2);
	*circular = (vars.impact->x < 0 ? 1.0 - rt_vector_angle(&tmp, &tmp2)
	/ (2.0 * M_PI) : rt_vector_angle(&tmp, &tmp2) / (2.0 * M_PI)) * w;
	if (vars.obj->type == CYLINDER)
		height = fmod(vars.impact->z, 2.0 * M_PI * vars.obj->ray) * h
	/ (2.0 * M_PI * vars.obj->ray);
	height = fmod(vars.impact->z, 4.0) * h / 4.0;
	if (height < 0)
		height = h + height;
	return (height);
}
