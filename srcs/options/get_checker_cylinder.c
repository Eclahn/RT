/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_checker_cylinder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 02:09:47 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/28 03:07:41 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_float3	get_checker_cylinder(t_object *obj, t_float3 *impact, int target)
{
	int			step;
	float		circular;
	float		height;
	t_getpos	util;

	util.obj = obj;
	util.impact = impact;
	(void)target;
	height = get_pos_cylinder(util, &circular,
		obj->checkerdata.l, obj->checkerdata.w);
	step = ((int)height + (int)circular) % 2;
	if (step == 0)
		return (obj->checkerdata.color1);
	else
		return (obj->checkerdata.color2);
}
