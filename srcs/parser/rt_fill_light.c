/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_fill_light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:06:02 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/07 19:19:37 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_fill_light(xmlNodePtr ptr, t_light *light, uint64_t used,
			char *filename)
{
	xmlNodePtr	cur;
	int			i;

	i = 0;
	rt_get_string(ptr->parent, &(light)->name, PARSE_NAME);
	while (i < LIGHT_PARAM)
	{
		cur = ptr;
		while (cur && g_light[i].used & used)
		{
			if (!xmlStrcmp(cur->name, (xmlChar*)g_light[i].text))
			{
				(*g_light[i].f_prop)(cur,
								(void*)((uint64_t)light + g_light[i].offset),
								g_light[i].type);
				break ;
			}
			cur = cur->next;
		}
		if (!cur)
			rt_error(ERROR_NO_TAG, filename, 0,
				"missing tags in <'type of light'>");
		i++;
	}
}
