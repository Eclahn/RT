/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_noise_value_sphere.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 02:11:24 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/29 02:50:59 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_float3	get_noise_value_sphere(t_object *obj, t_float3 *impact, int target)
{
	float		lati;
	float		longi;
	t_float3	color;
	float		res;

	(void)target;
	get_pos_sphere(impact, &longi, &lati);
	res = octave((float)16 * longi, (float)16 * lati, obj->noisedata.octaves, \
									obj->noisedata.persistence);
	color.x = \
		res * obj->noisedata.color1.x + obj->noisedata.color2.x * (1 - res);
	color.y = \
		res * obj->noisedata.color1.y + obj->noisedata.color2.y * (1 - res);
	color.z = \
		res * obj->noisedata.color1.z + obj->noisedata.color2.z * (1 - res);
	return (color);
}
