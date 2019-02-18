/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_float3_min_max.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 00:27:53 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/23 19:25:56 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_float3_min_max(t_float3 *value, float min, float max)
{
	rt_float_min_max(&value->x, min, max);
	rt_float_min_max(&value->y, min, max);
	rt_float_min_max(&value->z, min, max);
}
