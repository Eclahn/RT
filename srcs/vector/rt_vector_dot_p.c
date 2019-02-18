/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vector_dot_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 19:26:04 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/23 19:28:36 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

float	rt_vector_dot_p(t_float3 *v1, t_float3 *v2)
{
	float	dotp;

	dotp = v1->x * v2->x + v1->y * v2->y + v1->z * v2->z;
	dotp = (dotp > 1 ? 1 : dotp);
	dotp = (dotp < -1 ? -1 : dotp);
	return (dotp);
}
