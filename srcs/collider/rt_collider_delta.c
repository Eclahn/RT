/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_collider_delta.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 02:08:38 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/23 17:31:28 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

/*
** delta = b^2 - 4ac
** si delta est positif, il y a deux distances
** si delta est egale a 0 on a une distance
** sinon on a pas de collision
** pour les distances on a :
** (-b -sqrt(delta)) / 2a
** (-b +sqrt(delta)) / 2a
*/

void	rt_collider_delta(t_double3 *abc, t_impact *i)
{
	double delta;

	delta = (double)abc->y * (double)abc->y - 4.0
			* (double)abc->x * (double)abc->z;
	if (delta >= 0)
	{
		delta = sqrt(delta);
		i->hit = TRUE;
		i->k1 = ((double)-abc->y + (double)delta) / (2.0 * (double)abc->x);
		i->k2 = ((double)-abc->y - (double)delta) / (2.0 * (double)abc->x);
	}
	else
		i->hit = FALSE;
}
