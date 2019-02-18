/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 08:29:30 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/26 07:43:27 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	call_parser(t_sdl *win, t_stock *stock)
{
	size_t i;

	i = 0;
	if (win->argc == 2)
	{
		if (rt_parser(stock, win->argv[1]) == 0)
			rt_error(ERROR_FATAL_PARSE, win->argv[1], 0, 0);
	}
	else
	{
		rt_error(ERROR_NO_PATH, "Raytracer", 0, "try again with 2 arguments");
		exit(-1);
	}
	stock->cur_scn = 0;
	while (i < stock->num_scn)
		stock->scene[i++].cur_cam = 0;
	stock->feed = 1;
}
