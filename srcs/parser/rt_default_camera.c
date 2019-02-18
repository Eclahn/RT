/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_default_camera.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 15:22:27 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/29 05:37:24 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_default_camera(t_cam *camera)
{
	ft_memset(camera, 0, sizeof(t_cam));
	camera->pitch = 1;
	camera->moved = MOVMENT_ALL;
	camera->alpha = 0.157;
	camera->fov = 1.57;
	camera->axis_x = (t_float3){.x = 1, .y = 0, .z = 0};
	camera->axis_y = (t_float3){.x = 0, .y = 1, .z = 0};
	camera->axis_z = (t_float3){.x = 0, .y = 0, .z = 1};
}
