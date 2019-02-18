/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_projection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 15:25:31 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/23 17:39:27 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

/*
** init_screen malloc un tableau de t_view afin de ne pas avoir a recalculer
** les vecteurs par pixels de l'ecran de projection.
** ce tableau est re-malloc si nécéssaire mais toujours re-remplis
** nb : il stock les origines ecran au lieu de la camera au cas ou pour une
** feature future
*/

static int	this_init_memory(size_t x_win, size_t y_win, t_view ***screen)
{
	static size_t	xwin;
	static size_t	ywin;

	if (x_win != xwin || y_win != ywin)
	{
		if (*screen)
			free(*screen);
		xwin = x_win;
		ywin = y_win;
		if (y_win > 0 && x_win > 0)
		{
			if (!(*screen = (t_view **)malloc(sizeof(t_view *) * y_win
					+ (sizeof(t_view) * x_win) * y_win)))
				return (-1);
			while (y_win-- > 0)
				*(*screen + y_win) = (t_view*)((uint64_t)(*screen)
						+ sizeof(t_view *) * ywin
						+ (sizeof(t_view) * xwin) * y_win);
			return (0);
		}
		return (-1);
	}
	return (0);
}

t_view		**rt_init_projection(size_t x_win, size_t y_win, float fov)
{
	static t_view **screen;

	if (this_init_memory(x_win, y_win, &screen))
		return (NULL);
	rt_vector_cam(x_win, y_win, screen, fov);
	return (screen);
}
