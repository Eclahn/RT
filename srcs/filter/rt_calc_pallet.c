/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_calc_pallet.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 07:26:55 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/26 07:27:06 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				color_r(int x, int y, t_sdl *win)
{
	int r;

	r = (int)(get_color_pixel(win, x, y, R) / 64 * 64);
	r = r < 0 ? 0 : r;
	return (r);
}

int				color_g(int x, int y, t_sdl *win)
{
	int g;

	g = (int)(get_color_pixel(win, x, y, G) / 64 * 64);
	g = g < 0 ? 0 : g;
	return (g);
}

int				color_b(int x, int y, t_sdl *win)
{
	int b;

	b = (int)(get_color_pixel(win, x, y, B) / 64 * 64);
	b = b < 0 ? 0 : b;
	return (b);
}
