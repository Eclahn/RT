/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mat_rxyz.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/24 03:03:06 by juthomas          #+#    #+#             */
/*   Updated: 2016/05/12 16:47:24 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

static void		ft_mat_rotx(float matx[3][3], float n)
{
	float		c;
	float		s;

	c = cosf(n);
	s = sinf(n);
	matx[0][0] = 1;
	matx[0][1] = 0;
	matx[0][2] = 0;
	matx[1][0] = 0;
	matx[1][1] = c;
	matx[1][2] = -s;
	matx[2][0] = 0;
	matx[2][1] = s;
	matx[2][2] = c;
}

static void		ft_mat_roty(float matx[3][3], float n)
{
	float		c;
	float		s;

	c = cosf(n);
	s = sinf(n);
	matx[0][0] = c;
	matx[0][1] = 0;
	matx[0][2] = s;
	matx[1][0] = 0;
	matx[1][1] = 1;
	matx[1][2] = 0;
	matx[2][0] = -s;
	matx[2][1] = 0;
	matx[2][2] = c;
}

static void		ft_mat_rotz(float matx[3][3], float n)
{
	float		c;
	float		s;

	c = cosf(n);
	s = sinf(n);
	matx[0][0] = c;
	matx[0][1] = -s;
	matx[0][2] = 0;
	matx[1][0] = s;
	matx[1][1] = c;
	matx[1][2] = 0;
	matx[2][0] = 0;
	matx[2][1] = 0;
	matx[2][2] = 1;
}

static void		ft_mat_blank(float matx[3][3])
{
	matx[0][0] = 0;
	matx[0][1] = 0;
	matx[0][2] = 0;
	matx[1][0] = 0;
	matx[1][1] = 0;
	matx[1][2] = 0;
	matx[2][0] = 0;
	matx[2][1] = 0;
	matx[2][2] = 0;
}

void			ft_mat_rxyz(float rx, float ry, float rz, float m[3][3])
{
	float		m1[3][3];
	float		m2[3][3];
	float		m3[3][3];

	ft_mat_blank(m);
	ft_mat_blank(m3);
	ft_mat_rotx(m1, rx);
	ft_mat_roty(m2, ry);
	ft_mtrx_mult(m2, m1, m3, 3);
	ft_mat_rotz(m1, rz);
	ft_mtrx_mult(m3, m1, m, 3);
}
