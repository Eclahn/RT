/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_fill_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 18:07:41 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/07 18:32:29 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_fill_scene(t_scene *scene, xmlNodePtr cur, char *filename)
{
	t_num			num;
	int				i;

	num = (t_num){.amb = 0, .lum = 0, .cam = 0, .obj = 0};
	cur = cur->children;
	while (cur)
	{
		i = 0;
		while (i < SCENE_PARAM)
		{
			if (!xmlStrcmp(cur->name, (xmlChar*)g_scene[i].text)
				&& g_scene[i].f_tag)
			{
				(*g_scene[i].f_tag)(cur, scene, &num, filename);
				break ;
			}
			i++;
		}
		cur = cur->next;
	}
}
