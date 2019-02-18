/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_fill_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:06:19 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/07 19:05:56 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_fill_camera(xmlNodePtr ptr, t_scene *scene, t_num *num,
			char *filename)
{
	xmlNodePtr	cur;
	int			i;

	i = 0;
	rt_get_string(ptr, &scene->cam[num->cam].name, PARSE_NAME);
	ptr = ptr->children;
	while (i < CAM_PARAM)
	{
		cur = ptr;
		while (cur)
		{
			if (!xmlStrcmp(cur->name, (xmlChar*)g_cam[i].text))
			{
				(*g_cam[i].f_prop)(cur,
				(void*)((uint64_t) & scene->cam[num->cam] + g_cam[i].offset),
				g_cam[i].type);
				break ;
			}
			cur = cur->next;
		}
		if (!cur)
			rt_error(ERROR_NO_TAG, filename, 0, "missing tags in <camera>");
		i++;
	}
	num->cam += 1;
}
