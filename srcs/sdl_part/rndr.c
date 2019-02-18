/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rndr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 18:34:49 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/29 14:09:08 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		create_rndr_i(t_sdl *win)
{
	if (!(win->rndr_i))
		win->rndr_i = SDL_CreateRenderer(win->wini, 0,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (win->rndr_i == NULL)
	{
		return (-1);
	}
	return (0);
}
