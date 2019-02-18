/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_look_lights.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 19:29:23 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/26 05:26:44 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_look_lights(t_refl_refr *ref, const t_scene *scene,
			const t_visible *v, const t_float3 *vector)
{
	size_t		i;
	t_float3	transparency;
	t_light		lum;

	i = 0;
	ref->visible = v->visible;
	while (i < scene->num_lum)
	{
		if (scene->light[i].type == L_DIRECTIONAL)
			transparency = rt_impact_to_light_directional(&ref->impact[0],
			&scene->light[i], scene, ref);
		else
			transparency = rt_impact_to_light_spot(&ref->impact[0],
			&scene->light[i], scene, ref);
		if (transparency.x > EPSILON || transparency.y > EPSILON
			|| transparency.z > EPSILON)
		{
			lum = scene->light[i];
			rt_float3_mult(&lum.luminance, &transparency, &lum.luminance);
			rt_light(&scene->object[v->visible], &lum, ref, vector);
		}
		i++;
	}
}
