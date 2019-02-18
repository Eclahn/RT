/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_recurse_refraction.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:58:47 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/23 18:09:29 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_float3	rt_recurse_refraction(t_float3 *vector, t_float3 *normal, float n)
{
	t_float3	vector_i;
	t_float3	recurse;
	float		teta1;
	float		teta2;

	vector_i = (t_float3){.x = -vector->x, .y = -vector->y,
				.z = -vector->z};
	teta1 = rt_vector_dot_p(normal, &vector_i);
	teta2 = sqrtf(1 - (n * n) * (1 - teta1 * teta1));
	if (teta1 >= 0)
		teta1 = (n * teta1 - teta2);
	else
		teta1 = (n * teta1 + teta2);
	recurse.x = n * vector->x + teta1 * normal->x;
	recurse.y = n * vector->y + teta1 * normal->y;
	recurse.z = n * vector->z + teta1 * normal->z;
	rt_vector_normalize(&recurse);
	return (recurse);
}
