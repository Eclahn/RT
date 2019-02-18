/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_main_side.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 07:52:10 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/29 11:20:46 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			event_main_side_wait(t_sdl *win)
{
	SDL_LockMutex(win->m_event);
	win->b_event = SDL_FALSE;
	win->event_pov = 0;
	win->event_cam = 0;
	while (!win->b_event)
		SDL_CondWait(win->c_event, win->m_event);
	SDL_UnlockMutex(win->m_event);
}

static int		this_event_pov_p2(t_sdl *win)
{
	if (win->event_pov == SWITCH_SCENE_NEXT)
		win->stock.cur_scn += (win->stock.cur_scn < win->stock.num_scn - 1 ? 1
			: -win->stock.cur_scn);
	else if (win->event_pov == SWITCH_SCENE_PREV)
		win->stock.cur_scn -= (win->stock.cur_scn > 0 ? 1 : win->stock.cur_scn
		- (win->stock.num_scn - 1));
	else if (win->event_pov == SWITCH_CAM_NEXT)
		win->stock.scene[win->stock.cur_scn].cur_cam +=
			(win->stock.scene[win->stock.cur_scn].cur_cam <
			win->stock.scene[win->stock.cur_scn].num_cam - 1 ?
			1 : -win->stock.scene[win->stock.cur_scn].cur_cam);
	else if (win->event_pov == SWITCH_CAM_PREV)
		win->stock.scene[win->stock.cur_scn].cur_cam -=
			(win->stock.scene[win->stock.cur_scn].cur_cam > 0 ?
			1 : win->stock.scene[win->stock.cur_scn].cur_cam
			- (win->stock.scene[win->stock.cur_scn].num_cam - 1));
	else
		return (0);
	return (1);
}

static void		this_event_pov(t_sdl *win, t_float3 **screen)
{
	static SDL_Texture	*save;
	static t_float3		*save_s;
	SDL_Texture			*tmp;

	if (this_event_pov_p2(win))
		;
	else if (win->event_pov == SWITCH_WIN_SIZE)
	{
		apply_sizewin(&win->stock, win);
		if (save)
			SDL_DestroyTexture(save);
		save = win->tex;
		tmp = SDL_CreateTexture(win->rndr, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_STREAMING, win->coord.x_win, win->coord.y_win);
		SDL_LockTexture(tmp, NULL, (void**)&win->pixel, &win->coord.line);
		SDL_SetTextureBlendMode(tmp, SDL_BLENDMODE_BLEND);
		win->tex = tmp;
		if (save_s)
			free(save_s);
		save_s = *screen;
		if (!(*screen = (t_float3*)malloc(sizeof(t_float3)
			* win->coord.x_win * win->coord.y_win)))
			exit(-1);
	}
	win->scene = win->stock.scene[win->stock.cur_scn];
}

void			event_main_side(t_sdl *win, t_float3 **screen)
{
	SDL_LockMutex(win->m_event);
	if (win->event_pov)
	{
		this_event_pov(win, screen);
		win->cam = win->scene.cam[win->scene.cur_cam];
		win->cam.moved = MOVMENT_ALL;
	}
	if (win->event_cam)
	{
		rt_scene_camera((size_t)win->event_cam, &win->cam);
		win->cam.moved = MOVMENT_ALL;
	}
	rt_update_buffer(&win->scene, &win->cam);
	SDL_UnlockMutex(win->m_event);
}
