/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_collider_plane.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 03:37:34 by juthomas          #+#    #+#             */
/*   Updated: 2018/05/22 02:10:34 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

/*
** l'equation du plan étant z = 0,
** si Vz n'est pas nul :
**  - on trouve directement sa collision avec k = - Zpos / Vz
** sinon il n'y a pas de collision
*/

void	rt_collider_plane(t_float3 *origin, t_float3 *vector,
										const t_object *plane, t_impact *i)
{
	i->hit = TRUE;
	i->k1 = -origin->z / vector->z;
	i->k2 = i->k1;
	rt_apply_limits(plane, i, vector, origin);
}
