/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_matrix_apply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 05:12:45 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/21 19:01:49 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

t_float3	rt_matrix_apply(t_float3 *vector, float matrix[3][3])
{
	t_float3 result;

	result.x = vector->x * matrix[0][0] + vector->y * matrix[0][1] + vector->z
				* matrix[0][2];
	result.y = vector->x * matrix[1][0] + vector->y * matrix[1][1] + vector->z
				* matrix[1][2];
	result.z = vector->x * matrix[2][0] + vector->y * matrix[2][1] + vector->z
				* matrix[2][2];
	return (result);
}
