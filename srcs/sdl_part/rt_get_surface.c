/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_get_surface.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 07:42:55 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/25 07:43:58 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

SDL_Surface	*rt_get_surface(int type, const char *path)
{
	SDL_Surface *tmp;

	tmp = NULL;
	if (type & (TYPE_SVG | TYPE_PNG))
		tmp = IMG_Load(path);
	else if (type & TYPE_BMP)
		tmp = SDL_LoadBMP(path);
	if (!tmp)
		rt_error(ERROR_OPEN_IMG, path, 0, "get surface");
	return (tmp);
}
