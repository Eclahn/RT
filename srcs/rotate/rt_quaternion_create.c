/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_quaternion_create.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 07:50:27 by juthomas          #+#    #+#             */
/*   Updated: 2018/03/09 15:35:58 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	rt_quaternion_create(t_float3 *axis, float alpha, t_float4 *quaternion)
{
	float		a;
	float		s_a;

	a = alpha / 2.0;
	s_a = sinf(a);
	quaternion->w = cosf(a);
	quaternion->x = axis->x * s_a;
	quaternion->y = axis->y * s_a;
	quaternion->z = axis->z * s_a;
}
