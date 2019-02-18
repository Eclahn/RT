/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_origin_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 00:44:20 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/23 17:36:29 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

/*
** Ce calcul dependant uniquement de la position de la camera et de celle
** de l'objet on le calcul pour chaque objets avant de boucler sur les pixels
*/

void	rt_origin_object(const t_float3 *origin, const t_object *object,
			t_float3 *const new_origin)
{
	new_origin->x = origin->x - object->pos.x;
	new_origin->y = origin->y - object->pos.y;
	new_origin->z = origin->z - object->pos.z;
}
