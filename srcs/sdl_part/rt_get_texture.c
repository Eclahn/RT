/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_get_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 07:43:35 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/25 07:43:54 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

SDL_Texture	*rt_get_texture(int type, const char *path, SDL_Renderer *renderer)
{
	SDL_Surface	*surface;
	SDL_Texture	*texture;

	surface = rt_get_surface(type, path);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	if (!texture)
		rt_error(ERROR_OPEN_IMG, path, 0, "get texture");
	return (texture);
}
