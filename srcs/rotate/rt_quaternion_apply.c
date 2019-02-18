/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_quaternion_apply.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:27:05 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/21 19:01:05 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	rt_quaternion_apply(t_float4 *q, t_float3 v, t_float3 *result)
{
	float values[9];

	values[0] = q->w * q->x;
	values[1] = q->w * q->y;
	values[2] = q->w * q->z;
	values[3] = -q->x * q->x;
	values[4] = q->x * q->y;
	values[5] = q->x * q->z;
	values[6] = -q->y * q->y;
	values[7] = q->y * q->z;
	values[8] = -q->z * q->z;
	result->x = 2 * ((values[6] + values[8]) * v.x + (values[4] - values[2])
				* v.y + (values[1] + values[5]) * v.z) + v.x;
	result->y = 2 * ((values[2] + values[4]) * v.x + (values[3] + values[8])
				* v.y + (values[7] - values[0]) * v.z) + v.y;
	result->z = 2 * ((values[5] - values[1]) * v.x + (values[0] + values[7])
				* v.y + (values[3] + values[6]) * v.z) + v.z;
}
