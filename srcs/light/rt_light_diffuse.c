/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_light_diffuse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 02:07:03 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/23 17:49:18 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	rt_light_diffuse(const t_float3 *color_obj, const t_float3 *lightning,
			const float alpha_nl, t_float3 *target)
{
	t_float3	color;

	rt_float3_mult(color_obj, lightning, &color);
	target->x += color.x * alpha_nl;
	target->y += color.y * alpha_nl;
	target->z += color.z * alpha_nl;
}
