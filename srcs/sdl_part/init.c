/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 03:53:05 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/29 14:08:49 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		init_all(t_sdl *win, t_events *action)
{
	initialize(win);
	if (IMG_Init(IMG_INIT_WEBP) == -1)
		rt_error(ERROR_INIT_IMG, __FILE__, __LINE__, 0);
	if (TTF_Init() == -1)
		rt_error(ERROR_INIT_TTF, __FILE__, __LINE__, 0);
	win->m_event = SDL_CreateMutex();
	win->c_event = SDL_CreateCond();
	create_thread(win);
	win->init.init_all = init_all1(win, action);
	return (0);
}

void	initialize(t_sdl *win)
{
	win->coord.x_win = 1920;
	win->coord.y_win = 1080;
	win->coord.x_wini = X_WIN_I;
	win->coord.y_wini = Y_WIN_I;
	win->init.init_interface = init_interface(win);
	win->init.init = create_win_scene1(win);
}

int		init_all1(t_sdl *win, t_events *action)
{
	int i;

	rt_parse_button(win);
	i = 0;
	while (i < INTERFACE_ALL)
	{
		win->interface[i] = rt_create_background(win,
			&g_background[g_interface[i].bg],
				g_interface[i].text, g_interface[i].s_text);
		i++;
	}
	SDL_UnlockTexture(win->tex);
	SDL_RenderCopy(win->rndr, win->tex, NULL, NULL);
	win->init.init_event = init_event(win, action);
	SDL_DestroyTexture(win->tex);
	SDL_DestroyRenderer(win->rndr);
	SDL_DestroyWindow(win->win);
	return (0);
}

int		create_win_scene1(t_sdl *win)
{
	void		*tmp;
	uint32_t	*pixel;

	if (win)
	{
		win->win = SDL_CreateWindow("RTV_1", 100, 100,
			win->coord.x_win, win->coord.y_win, SDL_WINDOW_RESIZABLE);
		if (win->win == NULL)
			rt_error(ERROR_CREATE_SDL, __FILE__, __LINE__, "window");
		win->rndr = SDL_CreateRenderer(win->win, -1,
			SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (win->rndr == NULL)
			rt_error(ERROR_CREATE_SDL, __FILE__, __LINE__, "renderer");
		pixel = NULL;
		win->tex = SDL_CreateTexture(win->rndr, SDL_PIXELFORMAT_RGBA8888,
			SDL_TEXTUREACCESS_STREAMING, win->coord.x_win, win->coord.y_win);
		if (win->tex == NULL)
			rt_error(ERROR_CREATE_SDL, __FILE__, __LINE__, "texture");
		win->pix = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
		SDL_LockTexture(win->tex, NULL, &tmp, &win->coord.line);
		SDL_SetTextureBlendMode(win->tex, SDL_BLENDMODE_BLEND);
		pixel = (uint32_t *)tmp;
		win->pixel = pixel;
	}
	return (0);
}

int		init_interface(t_sdl *win)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) < 0)
	{
		return (-1);
	}
	win->wini = SDL_CreateWindow("Interface", 1900, 300,
		win->coord.x_wini, win->coord.y_wini, SDL_WINDOW_SHOWN);
	if (win->wini == NULL)
	{
		return (-1);
	}
	win->init.init_rndr_i = (*g_rndr[RNDR_1])(win);
	if (SDL_RenderClear(win->rndr_i) < 0)
		return (-1);
	return (0);
}
