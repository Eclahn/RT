/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_checker_plane.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 02:08:56 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/28 03:08:36 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_float3	get_checker_plane(t_object *obj, t_float3 *impact, int target)
{
	int		step;
	float	x;
	float	y;
	int		tmp;

	(void)target;
	x = fmod(impact->x, obj->checkerdata.w) >= 0 ? fmod(impact->x,
	obj->checkerdata.w) : obj->checkerdata.w + 1 - fmod(impact->x,
	obj->checkerdata.w);
	y = fmod(impact->y, obj->checkerdata.l) >= 0 ? fmod(impact->y,
	obj->checkerdata.l) : obj->checkerdata.l + 1 - fmod(impact->y,
	obj->checkerdata.l);
	tmp = (int)x + (int)y;
	step = tmp % 2;
	if (step == 0)
		return (obj->checkerdata.color1);
	else
		return (obj->checkerdata.color2);
}
