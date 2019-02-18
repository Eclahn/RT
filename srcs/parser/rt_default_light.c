/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_default_light.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 15:23:03 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/13 23:16:20 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_default_light(t_light *light)
{
	ft_memset(light, 0, sizeof(t_light));
	light->intensity = 0.1;
	light->ray = 0.1;
	light->color = (t_float3){.x = 1, .y = 1, .z = 1};
}
