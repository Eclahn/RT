/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_collider_normal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 03:07:19 by juthomas          #+#    #+#             */
/*   Updated: 2018/05/22 02:10:02 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static void	this_oriented_normal(t_float3 *vector, t_float3 *normal)
{
	float	angle;

	angle = rt_vector_angle(normal, vector);
	angle += (angle >= 3.0 * M_PI / 2.0 ? -2.0 * M_PI : 0.0);
	if (-M_PI / 2.0 <= angle && angle <= M_PI / 2.0)
	{
		normal->x *= -1;
		normal->y *= -1;
		normal->z *= -1;
	}
}

t_float3	rt_collider_normal(t_object *object, t_float3 *origin,
													t_float3 *vector, float k)
{
	t_float3	normal;

	if (object->type == PLANE || object->type == DISK)
	{
		if (origin->z >= 0.0)
			normal = (t_float3){.x = 0.0, .y = 0.0, .z = 1.0};
		else
			normal = (t_float3){.x = 0.0, .y = 0.0, .z = -1.0};
		rt_vector_normalize(&normal);
	}
	else
	{
		normal = rt_vector_impact(origin, vector, k);
		if (object->type == CYLINDER)
			normal.z = 0.0;
		else if (object->type == CONE)
			normal.z -= (normal.z < 0 ? -1 : 1) * (sqrtf(powf(normal.z, 2)
			+ powf(normal.y, 2) + powf(normal.x, 2)) / cosf(object->alpha));
		rt_vector_normalize(&normal);
		this_oriented_normal(vector, &normal);
	}
	return (normal);
}
