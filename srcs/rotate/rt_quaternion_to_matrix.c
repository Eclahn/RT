/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_quaternion_to_matrix.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 10:56:01 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/21 19:00:30 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	rt_quaternion_to_matrix(t_float4 *q, float m[3][3])
{
	float	values[9];

	values[0] = q->x * q->x;
	values[1] = q->x * q->y;
	values[2] = q->x * q->z;
	values[3] = q->x * q->w;
	values[4] = q->y * q->y;
	values[5] = q->y * q->z;
	values[6] = q->y * q->w;
	values[7] = q->z * q->z;
	values[8] = q->z * q->w;
	m[0][0] = 1 - 2 * (values[4] + values[7]);
	m[0][1] = 2 * (values[1] - values[8]);
	m[0][2] = 2 * (values[2] + values[6]);
	m[1][0] = 2 * (values[1] + values[8]);
	m[1][1] = 1 - 2 * (values[0] + values[7]);
	m[1][2] = 2 * (values[5] - values[3]);
	m[2][0] = 2 * (values[2] - values[6]);
	m[2][1] = 2 * (values[5] + values[3]);
	m[2][2] = 1 - 2 * (values[0] + values[4]);
}
