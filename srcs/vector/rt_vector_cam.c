/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_vector_cam.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 20:39:44 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/23 19:30:00 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

/*
** on considère une caméra en {0, 0, 0} orienté vers les x positifs
** et un ecran de projection placé en :
** x = 1
** un fov de 90 degré en radian => fov = 1.5708
**
**                 z             x (nord)
**                  |          /
**                  |        /
**                  |      /
**                  |    /
**                  |  /
**  -y (ouest) _____|/________ y (est)
**                 /|
**               /  |
**             /    |
**           /      |
**        -x (sud)   -z (altitude)
*/

void	rt_vector_cam(const size_t xwin, const size_t ywin, t_view **screen,
	const float fov)
{
	size_t	x;
	size_t	y;
	float	pitch;

	pitch = tanf(fov / 2.0) * 2.0 / xwin;
	y = 0;
	while (y < ywin)
	{
		x = 0;
		while (x < xwin)
		{
			screen[y][x].vector = (t_float3){.x = 1.0,
								.y = pitch * 0.5 + pitch * (x - xwin / 2.0),
								.z = pitch * -0.5 - pitch * (y - ywin / 2.0)};
			screen[y][x].origin = (t_float3){.x = 0,
											.y = screen[y][x].vector.y,
											.z = screen[y][x].vector.z};
			rt_vector_normalize(&screen[y][x].vector);
			x++;
		}
		y++;
	}
}
