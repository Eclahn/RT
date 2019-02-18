/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_translate_screen.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 08:40:17 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/23 17:37:30 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_translate_screen(t_float3 *vector, t_view **screen,
			size_t x, size_t y)
{
	size_t	i;
	size_t	j;

	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			screen[j][i].origin.x += vector->x;
			screen[j][i].origin.y += vector->y;
			screen[j][i].origin.z += vector->z;
			i++;
		}
		j++;
	}
}
