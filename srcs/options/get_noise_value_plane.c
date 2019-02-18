/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_noise_value_plane.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 02:12:32 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/29 02:38:56 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_float3	get_noise_value_plane(t_object *obj, t_float3 *impact, int target)
{
	float		x;
	float		y;
	float		res;
	t_float3	color;

	(void)target;
	(void)obj;
	x = fmod(impact->x, 16);
	y = fmod(impact->y, 16);
	if (x < 0)
		x = 16 + x;
	if (y < 0)
		y = 16 + y;
	res = octave(x, y, obj->noisedata.octaves, obj->noisedata.persistence);
	color.x = \
		res * obj->noisedata.color1.x + obj->noisedata.color2.x * (1 - res);
	color.y = \
		res * obj->noisedata.color1.y + obj->noisedata.color2.y * (1 - res);
	color.z = \
		res * obj->noisedata.color1.z + obj->noisedata.color2.z * (1 - res);
	return (color);
}
