/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_rotate_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 08:34:29 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/23 17:37:46 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_rotate_screen(t_float4 *quaternion, t_view **screen,
			size_t x, size_t y)
{
	size_t	i;
	size_t	j;
	float	matrix[3][3];

	rt_quaternion_to_matrix(quaternion, matrix);
	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			screen[j][i].origin = rt_matrix_apply(&screen[j][i].origin, matrix);
			screen[j][i].vector = rt_matrix_apply(&screen[j][i].vector, matrix);
			i++;
		}
		j++;
	}
}
