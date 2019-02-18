/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 03:53:05 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/10 04:02:19 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		rt_parser(t_stock *stock, char *filename)
{
	xmlDocPtr	doc;
	xmlNodePtr	cur;

	stock->num_scn = 0;
	rt_open_xml(&doc, &cur, filename);
	rt_malloc(&stock, cur, filename);
	rt_default_scene(stock);
	rt_fill(cur, &stock, filename);
	xmlFreeDoc(doc);
	rt_post_computing(stock, filename);
	return (1);
}
