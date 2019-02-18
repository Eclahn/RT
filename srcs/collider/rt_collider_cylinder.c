/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_collider_cylinder.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 23:26:33 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/10 17:04:25 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

/*
** l'equation du cylindre étant
** x^2 + y^2 + z^2 - (ax + by + cz)^2 / (a^2 + b^2 + c^2) = R^2
** a b et c ici sont les valeurs du vecteur directionnel du cylindre,
** ici on prendra l'axe z
** après simplification on obtiens : x^2 + y^2 = R^2
** on calcul a, b et c tel que ak^2 + bk + c = 0
** on y integre l'equation de la droite (origine + vecteur)
** x = Xpos + kVx
** y = Ypos + kVy
** z = Zpos + kVz
** Avec :
**      - Xpos, Ypos et Zpos la position de la caméra, on a pris ici la
**      position inverse de l'objet afin de placer ce dernier en (0,0,0)
**      - Vx, Vy et Vz le vecteur concerné de la caméra
**      - k, la distance caméra <=> intersection que l'on cherche
** Ce qui nous donne (sans la position inverse) :
** a = Vx^2 + Vy^2
** b = 2 * (Xpos * Vx + Ypos * Vy)
** c = Xpos^2 + Ypos^2 - R^2
*/

void	rt_collider_cylinder(t_float3 *origin, t_float3 *vector,
									const t_object *cylinder, t_impact *i)
{
	t_double3 abc;

	abc.x = powf(vector->x, 2) + powf(vector->y, 2);
	abc.y = 2.0 * (origin->x * vector->x + origin->y * vector->y);
	abc.z = powf(origin->x, 2) + powf(origin->y, 2) - powf(cylinder->ray, 2);
	rt_collider_delta(&abc, i);
	rt_apply_limits(cylinder, i, vector, origin);
}
