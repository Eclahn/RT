/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vector_cross_p.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/27 16:32:34 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/23 17:29:07 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_float3	rt_vector_cross_p(t_float3 *v1, t_float3 *v2)
{
	t_float3	cross;

	cross.x = v1->y * v2->z - v1->z * v2->y;
	cross.y = v1->x * v2->z - v1->z * v2->x;
	cross.z = v1->x * v2->y - v1->y * v2->x;
	return (cross);
}
