/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_check_scene.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 18:29:19 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/07 18:18:02 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_check_scene(t_num *num, xmlNodePtr cur, char *filename)
{
	int i;

	*num = (t_num){.amb = 0, .lum = 0, .cam = 0, .obj = 0};
	if (!cur)
		rt_error(ERROR_NO_TAG, filename, 0, "<.../>");
	while (cur)
	{
		i = 0;
		while (i < SCENE_PARAM)
		{
			if (!xmlStrcmp(cur->name, (xmlChar*)g_scene[i].text))
			{
				*((int*)((uint64_t)num + g_scene[i].offset)) += 1;
			}
			i++;
		}
		cur = cur->next;
	}
}
