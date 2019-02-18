/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parse_button.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 07:46:06 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/25 07:48:10 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		rt_parse_button(t_sdl *win)
{
	int		i;

	i = 0;
	while (i < BUTTON_ALL)
	{
		win->button[i].normal = rt_get_texture(g_button[i].n_type,
			g_button[i].n_path, win->rndr_i);
		win->button[i].hover = rt_get_texture(g_button[i].h_type,
			g_button[i].h_path, win->rndr_i);
		i++;
	}
}
