/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_collider_disk.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/04 00:14:38 by juthomas          #+#    #+#             */
/*   Updated: 2018/05/22 02:08:25 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

/*
** l'equation du disque étant x^2 + y^2 <= R^2,
** si Vz n'est pas nul et que :
**  - on trouve directement sa collision avec k = - Zpos / Vz
** cette collision est temporaire et symbolise la collision avec le plan
** on vérifie que l'impact se situe dans le rayon correspondant du disque
** si c'est le cas on a collision
** sinon il n'y a pas de collision
*/

void	rt_collider_disk(t_float3 *origin, t_float3 *vector,
										const t_object *disk, t_impact *i)
{
	t_float3 v_i;

	i->hit = FALSE;
	i->k1 = -origin->z / vector->z;
	v_i = rt_vector_impact(origin, vector, i->k1);
	if (powf(v_i.x, 2) + powf(v_i.y, 2) <= powf(disk->ray, 2))
	{
		i->hit = TRUE;
		i->k2 = i->k1;
	}
	rt_apply_limits(disk, i, vector, origin);
}
