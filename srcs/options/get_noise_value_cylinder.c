/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_noise_value_cylinder.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 02:11:57 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/29 02:38:31 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_float3	get_noise_value_cylinder(t_object *obj, t_float3 *impact, \
															int target)
{
	float		circular;
	float		height;
	t_getpos	util;
	float		res;
	t_float3	color;

	(void)target;
	util.obj = obj;
	util.impact = impact;
	height = get_pos_cylinder(util, &circular, 256, 1);
	res = octave(height / 16, circular * 16, obj->noisedata.octaves, \
											obj->noisedata.persistence);
	color.x = \
		res * obj->noisedata.color1.x + obj->noisedata.color2.x * (1 - res);
	color.y = \
		res * obj->noisedata.color1.y + obj->noisedata.color2.y * (1 - res);
	color.z = \
		res * obj->noisedata.color1.z + obj->noisedata.color2.z * (1 - res);
	return (color);
}
