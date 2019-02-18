/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 18:07:55 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/21 12:52:28 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_fill(xmlNodePtr cur, t_stock **stock, char *filename)
{
	int cur_scn;

	cur_scn = 0;
	while (cur)
	{
		if (!xmlStrcmp(cur->name, (xmlChar*)"scene"))
		{
			rt_get_string(cur, &(*stock)->scene[cur_scn].name, PARSE_NAME);
			rt_fill_scene(&(*stock)->scene[cur_scn], cur, filename);
			cur_scn++;
		}
		cur = cur->next;
	}
	(*stock)->cur_scn = 0;
}
