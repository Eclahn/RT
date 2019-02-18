/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 22:20:30 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/29 03:16:21 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		fill_matrix(float matrix[3][3], t_float3 *t,
				t_float3 *b, t_float3 *n)
{
	matrix[0][0] = t->x;
	matrix[0][1] = b->x;
	matrix[0][2] = n->x;
	matrix[1][0] = t->y;
	matrix[1][1] = b->y;
	matrix[1][2] = n->y;
	matrix[2][0] = t->z;
	matrix[2][1] = b->z;
	matrix[2][2] = n->z;
}

t_float3	rotate_normal(t_float3 *tex_normal,
				t_float3 *obj_normal, t_float3 *dir)
{
	t_float3	tangent;
	t_float3	btangent;
	float		matrix[3][3];

	tangent = rt_vector_cross_p(obj_normal, dir);
	rt_vector_normalize(&tangent);
	btangent = rt_vector_cross_p(&tangent, obj_normal);
	rt_vector_normalize(&btangent);
	fill_matrix(matrix, &tangent, &btangent, obj_normal);
	return (rt_matrix_apply(tex_normal, matrix));
}
