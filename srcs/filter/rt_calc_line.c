/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_calc_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 07:26:47 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/26 07:26:49 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				calc_fr(t_sdl *win, int x, int y)
{
	int r1;
	int r2;
	int fr;

	r1 = (get_color_pixel(win, x, y, R));
	r2 = (get_color_pixel(win, (x + 1 >
			(int)win->scene.x_win ? x : x + 1), y, R));
	fr = r1 - r2;
	return (fr);
}

int				calc_fg(t_sdl *win, int x, int y)
{
	int g1;
	int g2;
	int fg;

	g1 = (get_color_pixel(win, x, y, G));
	g2 = (get_color_pixel(win, (x + 1 >
			(int)win->scene.x_win ? x : x + 1), y, G));
	fg = g1 - g2;
	return (fg);
}

int				calc_fb(t_sdl *win, int x, int y)
{
	int b1;
	int b2;
	int fb;

	b1 = (get_color_pixel(win, x, y, B));
	b2 = (get_color_pixel(win, (x + 1 >
			(int)win->scene.x_win ? x : x + 1), y, B));
	fb = b1 - b2;
	return (fb);
}
