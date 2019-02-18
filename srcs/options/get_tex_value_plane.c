/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_value_plane.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 02:04:55 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/29 02:54:49 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_float3	get_tex_value_plane(t_object *obj, t_float3 *impact, int target)
{
	t_float3	color;
	int			x;
	int			y;
	t_uint8_3	ucolor;

	x = fmod(impact->x * obj->texture[target]->w / 4, obj->texture[target]->w);
	y = fmod(impact->y * obj->texture[target]->h / 4, obj->texture[target]->h);
	if (x < 0)
		x = obj->texture[target]->w + x;
	if (y < 0)
		y = obj->texture[target]->h + y;
	SDL_GetRGB(getpixel(obj->texture[target], x, y),
	obj->texture[target]->format, &(ucolor.r), &(ucolor.g), &(ucolor.b));
	color.x = ucolor.r / 255.0;
	color.y = ucolor.g / 255.0;
	color.z = ucolor.b / 255.0;
	return (color);
}
