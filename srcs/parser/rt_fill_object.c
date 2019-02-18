/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_fill_object.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:13:10 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/26 18:47:57 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_fill_object(xmlNodePtr ptr, t_object *object, uint64_t used,
			char *filename)
{
	xmlNodePtr	cur;
	int			i;

	rt_get_string(ptr->parent, &(object)->name, PARSE_NAME);
	i = 0;
	while (i < OBJECT_PARAM)
	{
		cur = ptr;
		while (cur && g_object[i].used & used)
		{
			if (!xmlStrcmp(cur->name, (xmlChar*)g_object[i].text))
			{
				(*g_object[i].f_prop)(cur,
							(void*)((uint64_t)object + g_object[i].offset),
							g_object[i].type);
				break ;
			}
			cur = cur->next;
		}
		if (!cur)
			rt_error(ERROR_NO_TAG, filename, 0,
				"missing tags in <'type of object'>");
		i++;
	}
}
