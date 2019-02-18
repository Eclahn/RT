/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vector_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 01:43:01 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/23 19:27:50 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

float	rt_vector_angle(t_float3 *v1, t_float3 *v2)
{
	float	alpha;

	alpha = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
	alpha = (alpha > 1 ? 1 : alpha);
	alpha = (alpha < -1 ? -1 : alpha);
	alpha = acosf(alpha);
	return (alpha);
}
