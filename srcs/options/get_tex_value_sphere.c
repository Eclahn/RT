/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_value_sphere.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 02:06:57 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/29 03:08:14 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_float3	get_tex_value_sphere(t_object *obj, t_float3 *impact, int target)
{
	float		lati_longi[2];
	t_float3	color;
	uint8_t		x;
	uint8_t		y;
	uint8_t		z;

	get_pos_sphere(impact, &lati_longi[1], &lati_longi[0]);
	SDL_GetRGB(getpixel(obj->texture[target], obj->texture[target]->w
	* (lati_longi[1]),
	obj->texture[target]->h * lati_longi[0]),
	obj->texture[target]->format, &x, &y, &z);
	color.x = x / 255.0;
	color.y = y / 255.0;
	color.z = z / 255.0;
	return (color);
}
