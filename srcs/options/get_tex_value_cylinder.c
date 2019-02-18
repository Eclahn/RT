/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_value_cylinder.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 02:05:52 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/29 02:53:43 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_float3	get_tex_value_cylinder(t_object *obj, t_float3 *impact, int target)
{
	float		circular;
	float		height;
	t_float3	color;
	t_uint8_3	ucolor;
	t_getpos	util;

	util.obj = obj;
	util.impact = impact;
	height = get_pos_cylinder(util, &circular, obj->texture[target]->h, 1);
	SDL_GetRGB(getpixel(obj->texture[target],
		obj->texture[target]->w * circular > obj->texture[target]->w - 1
		? obj->texture[target]->w - 1 : obj->texture[target]->w * circular,
		height > obj->texture[target]->h - 1
		? obj->texture[target]->h - 1 : height), obj->texture[target]->format,
		&(ucolor.r), &(ucolor.g), &(ucolor.b));
	color.x = ucolor.r / 255.0;
	color.y = ucolor.g / 255.0;
	color.z = ucolor.b / 255.0;
	return (color);
}
