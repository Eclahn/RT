/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_quaternion_to_euler.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 18:19:59 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/21 19:00:09 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_quaternion_to_euler(float *alpha, float *beta, float *omega,
			t_float4 *quaternion)
{
	float	sinr;
	float	cosr;
	float	sinp;
	float	siny;
	float	cosy;

	sinr = 2.0 * (quaternion->w * quaternion->x + quaternion->y
			* quaternion->z);
	cosr = 1.0 - 2.0 * (quaternion->x * quaternion->x + quaternion->y
			* quaternion->y);
	*alpha = atan2(sinr, cosr);
	sinp = 2.0 * (quaternion->w * quaternion->y - quaternion->z
			* quaternion->x);
	if (fabs(sinp) >= 1)
		*beta = copysign(M_PI / 2, sinp);
	else
		*beta = asin(sinp);
	siny = 2.0 * (quaternion->w * quaternion->z + quaternion->x
		* quaternion->y);
	cosy = 1.0 - 2.0 * (quaternion->y * quaternion->y + quaternion->z
		* quaternion->z);
	*omega = atan2(siny, cosy);
}
