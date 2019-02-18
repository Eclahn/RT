/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vector_normalize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 01:50:21 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/23 19:29:26 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	rt_vector_normalize(t_float3 *vector)
{
	float	norme;

	norme = sqrtf(powf(vector->x, 2) + powf(vector->y, 2) + powf(vector->z, 2));
	vector->x /= norme;
	vector->y /= norme;
	vector->z /= norme;
}
