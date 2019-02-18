/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_open_xml.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:02:45 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/09 22:03:47 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_open_xml(xmlDocPtr *doc, xmlNodePtr *cur, char *filename)
{
	(*doc) = xmlParseFile(filename);
	if (!(*doc))
		rt_error(ERROR_UNKNOW_FILE, filename, 0, "must be an valid XML file");
	(*cur) = xmlDocGetRootElement(*doc);
	if (!(*cur) || xmlStrcmp((*cur)->name, (xmlChar*)"folder"))
		rt_error(ERROR_NO_TAG, filename, 0, "<folder>");
	(*cur) = (*cur)->children;
}
