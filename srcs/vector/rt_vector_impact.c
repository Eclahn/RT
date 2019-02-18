/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vector_impact.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 07:48:47 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/23 19:28:13 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

t_float3	rt_vector_impact(t_float3 *origin, t_float3 *vector, float k)
{
	t_float3	impact;

	impact.x = vector->x * k + origin->x;
	impact.y = vector->y * k + origin->y;
	impact.z = vector->z * k + origin->z;
	return (impact);
}
