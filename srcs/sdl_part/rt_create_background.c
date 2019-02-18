/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_create_background.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 07:45:14 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/25 07:45:38 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

SDL_Texture	*rt_create_background(t_sdl *win, const t_picture *picture,
const t_text *tab, int len)
{
	SDL_Surface	*background;
	SDL_Surface	*text;
	SDL_Texture *bg;

	background = rt_get_surface(picture->n_type, picture->n_path);
	while (len--)
	{
		text = rt_get_text(tab[len].font, tab[len].text, tab[len].size);
		SDL_BlitSurface(text, NULL, background, (SDL_Rect*)&tab[len].rect);
		SDL_FreeSurface(text);
	}
	bg = SDL_CreateTextureFromSurface(win->rndr_i, background);
	SDL_FreeSurface(background);
	return (bg);
}
