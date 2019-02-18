/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 13:44:33 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/29 13:50:50 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	init_event_norm(t_sdl *win, int *pos_x, int *pos_y, Uint32 *m_state)
{
	SDL_PollEvent(&win->event);
	SDL_PumpEvents();
	if (win->wini == SDL_GetMouseFocus())
		(*m_state) = SDL_GetMouseState(pos_x, pos_y);
	else
	{
		(*m_state) = 0;
		(*pos_x) = 0;
		(*pos_y) = 0;
	}
}
