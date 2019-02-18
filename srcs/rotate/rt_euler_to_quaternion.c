/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_euler_to_quaternion.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 22:16:20 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/21 19:02:14 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	rt_euler_to_quaternion(float alpha, float beta, float omega,
			t_float4 *quaternion)
{
	t_float4	tmp;
	t_float3	axis;

	axis = (t_float3){.x = 1};
	rt_quaternion_create(&axis, alpha, &tmp);
	axis = (t_float3){.y = 1};
	rt_quaternion_create(&axis, beta, quaternion);
	rt_quaternion_multiply(*quaternion, tmp, quaternion);
	axis = (t_float3){.z = 1};
	rt_quaternion_create(&axis, omega, &tmp);
	rt_quaternion_multiply(tmp, *quaternion, quaternion);
}
