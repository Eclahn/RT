/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_float3_mult_float.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 11:07:55 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/23 19:27:13 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	rt_float3_mult_float(const t_float3 *v1, const float v2,
			t_float3 *result)
{
	result->x = v1->x * v2;
	result->y = v1->y * v2;
	result->z = v1->z * v2;
}
