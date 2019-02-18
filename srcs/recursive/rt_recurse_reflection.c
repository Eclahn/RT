/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_recurse_reflection.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:51:21 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/23 17:59:26 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_float3	rt_recurse_reflection(t_float3 *vector, t_float3 *normal)
{
	t_float3	reflected;
	float		tmp;

	tmp = 2 * rt_vector_dot_p(vector, normal);
	reflected.x = vector->x - tmp * normal->x;
	reflected.y = vector->y - tmp * normal->y;
	reflected.z = vector->z - tmp * normal->z;
	return (reflected);
}
