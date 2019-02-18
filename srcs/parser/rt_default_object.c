/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_default_object.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 15:22:43 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/11 15:49:06 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_default_object(t_object *object)
{
	ft_memset(object, 0, sizeof(t_object));
	object->ray = 1;
	object->limit_min = (t_float3){.x = -INFINITY, .y = -INFINITY,
						.z = -INFINITY};
	object->limit_max = (t_float3){.x = INFINITY, .y = INFINITY, .z = INFINITY};
}
