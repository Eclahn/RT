/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 22:45:33 by gsimeon           #+#    #+#             */
/*   Updated: 2018/06/29 14:02:29 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	apply_sizewin(t_stock *stock, t_sdl *win)
{
	size_t i;

	i = 0;
	while (i < stock->num_scn)
	{
		(stock->scene[i].x_win) = (win->coord.x_win);
		(stock->scene[i].y_win) = (win->coord.y_win);
		i++;
	}
}

void	multithreading_call(t_sdl *win, t_float3 *screen)
{
	SDL_Thread	*recurse[NUM_THREAD];
	t_thread	data[NUM_THREAD];
	int			thread;

	thread = 0;
	if (NUM_THREAD >= 1)
	{
		while (thread < NUM_THREAD)
		{
			data[thread] = (t_thread){.win = win, .thread = thread,
			.screen = screen};
			recurse[thread] =
				SDL_CreateThread(&rt_recurse, "Recurse", &data[thread]);
			thread++;
		}
		thread = 0;
		while (thread < NUM_THREAD)
			SDL_WaitThread(recurse[thread++], NULL);
	}
	else
	{
		data[thread] = (t_thread){.win = win, .thread = thread,
		.screen = screen};
		rt_recurse(&data[thread]);
	}
}

int		infinity_thread(void *data)
{
	t_sdl			*win;
	static t_float3	*screen;

	win = data;
	call_parser(win, &win->stock);
	apply_sizewin(&win->stock, win);
	if (!screen)
		if (!(screen = (t_float3*)malloc(sizeof(t_float3)
		* win->coord.x_win * win->coord.y_win)))
			exit(-1);
	win->scene = win->stock.scene[win->stock.cur_scn];
	win->cam = win->scene.cam[win->scene.cur_cam];
	while (1)
	{
		event_main_side(win, &screen);
		multithreading_call(win, screen);
		if (win->filter < F_ALL)
			rt_kernel_convolution(win, win->pixel, win->filter);
		else if (win->filter > F_ALL && win->filter <= F_CARTOON)
			rt_basic_filters(win, win->pixel, win->filter);
		event_main_side_wait(win);
	}
	return (0);
}

int		create_thread(t_sdl *win)
{
	win->thread_test = SDL_CreateThread(&infinity_thread, "Test", win);
	if (NULL == win->thread_test)
		exit(-1);
	return (0);
}

int		main(int argc, char **argv)
{
	t_events	action;
	t_sdl		win;
	int			i;

	ft_memset((void*)&action, 0, sizeof(t_events));
	ft_memset((void*)&win, 0, sizeof(t_sdl));
	win.filter = F_ALL;
	win.argc = argc;
	win.argv = argv;
	win.stock.feed = 0;
	i = init_all(&win, &action);
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
