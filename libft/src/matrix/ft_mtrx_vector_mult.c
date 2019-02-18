/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mtrx_vector_mult.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 23:48:55 by juthomas          #+#    #+#             */
/*   Updated: 2016/10/17 10:07:04 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_mtrx_vector_mult(float m[3][3], int *x, int *y, int *z)
{
	float	i;
	float	j;
	float	k;

	i = (float)*x;
	j = (float)*y;
	k = (float)*z;
	*x = (int)(i * m[0][0] + j * m[0][1] + k * m[0][2]);
	*y = (int)(i * m[1][0] + j * m[1][1] + k * m[1][2]);
	*z = (int)(i * m[2][0] + j * m[2][1] + k * m[2][2]);
}
