/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_get_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 07:44:15 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/25 07:44:34 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

SDL_Surface	*rt_get_text(char *path, char *text, int size)
{
	SDL_Color	black;
	TTF_Font	*font;
	SDL_Surface	*texture;

	black = (SDL_Color){.a=0, .r=20, .g=20, .b=20};
	font = TTF_OpenFont(path, size);
	texture = TTF_RenderText_Blended(font, text, black);
	TTF_CloseFont(font);
	return (texture);
}
