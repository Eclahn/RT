/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrx_mult.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 20:30:23 by juthomas          #+#    #+#             */
/*   Updated: 2016/04/30 00:03:05 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_mtrx_mult(float m1[3][3], float m2[3][3], float m[3][3], int n)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	while (n > y)
	{
		x = 0;
		while (n > x)
		{
			i = n + 1;
			while (--i)
				m[y][x] = m[y][x] + m1[y][n - i] * m2[n - i][x];
			x++;
		}
		y++;
	}
}
