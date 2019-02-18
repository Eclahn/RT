/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_checker_sphere.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 02:08:18 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/28 03:09:25 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_float3	get_checker_sphere(t_object *obj, t_float3 *impact, int target)
{
	float	lati;
	float	longi;
	int		step;

	(void)target;
	get_pos_sphere(impact, &longi, &lati);
	step = ((int)(longi * obj->checkerdata.w)
	+ (int)(lati * obj->checkerdata.l)) % 2;
	if (step == 0)
		return (obj->checkerdata.color1);
	else
		return (obj->checkerdata.color2);
}
