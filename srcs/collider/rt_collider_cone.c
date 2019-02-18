/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_collider_cone.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 02:38:48 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/23 17:31:16 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

/*
** x^2 + y^2 - cte * z^2 = 0
** avec cte = tan(angle)^2 ici précalculé et stocké dans ray
**
** (Xpos + kVx)^2 + (Ypos + kVy)^2 - cte * (Zpos + kVz)^2 = 0
**
** + Xpos^2
** + Ypos^2
** - cte * Zpos^2
**
** 2 (Xpos * kVx + Ypos * kVy - cte * Zpos * kVz)
**
** + kVx^2
** + kVy^2
** - cte * kVz^2
**
**  ICI PAS DE RAYON MAIS UNE CONSTANTE QUE L'ON STOCK DANS LE RAYON
*/

void	rt_collider_cone(t_float3 *origin, t_float3 *vector,
										const t_object *cone, t_impact *i)
{
	t_double3 abc;

	abc.x = (double)vector->x * (double)vector->x
			+ (double)vector->y * (double)vector->y
			- (double)cone->ray * (double)vector->z * (double)vector->z;
	abc.y = 2.0 * ((double)origin->x * (double)vector->x
			+ (double)origin->y * (double)vector->y
			- (double)cone->ray * (double)origin->z * (double)vector->z);
	abc.z = (double)origin->x * (double)origin->x
			+ (double)origin->y * (double)origin->y
			- (double)cone->ray * (double)origin->z * (double)origin->z;
	rt_collider_delta(&abc, i);
	rt_apply_limits(cone, i, vector, origin);
}
