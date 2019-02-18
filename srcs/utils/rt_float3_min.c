/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_float3_min.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 11:56:26 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/10 12:00:43 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	rt_float3_min(t_float3 *value, const float min)
{
	if (value->x < min)
		value->x = min;
	if (value->y < min)
		value->y = min;
	if (value->z < min)
		value->z = min;
}
