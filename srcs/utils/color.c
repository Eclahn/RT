/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 17:44:20 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/23 19:25:46 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void	rt_fix_color_negativ(float *x, float *y, float *z)
{
	*x = *x < 0 ? 0 : *x;
	*y = *y < 0 ? 0 : *y;
	*z = *z < 0 ? 0 : *z;
	*x = *x > 2 ? 2 : *x;
}

void		fix_color(float *x, float *y, float *z)
{
	t_float3	c;

	if (*x <= 1 && *y <= 1 && *z <= 1)
		return ;
	rt_fix_color_negativ(x, y, z);
	c.x = 1;
	c.y = *y < 1 ? *y + (1 - *y) * (*x - 1) : 1;
	c.z = *z < 1 ? *z + (1 - *z) * (*x - 1) : 1;
	if (*y >= *x && *y >= *z)
	{
		*y = *y > 2 ? 2 : *y;
		c.x = *x < 1 ? *x + (1 - *x) * (*y - 1) : 1;
		c.y = 1;
		c.z = *z < 1 ? *z + (1 - *z) * (*y - 1) : 1;
	}
	else if (*z >= *x && *z >= *y)
	{
		*z = *z > 2 ? 2 : *z;
		c.x = *x < 1 ? *x + (1 - *x) * (*z - 1) : 1;
		c.y = *y < 1 ? *y + (1 - *y) * (*z - 1) : 1;
		c.z = 1;
	}
	*x = c.x;
	*y = c.y;
	*z = c.z;
}
