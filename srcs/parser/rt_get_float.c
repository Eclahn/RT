/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_get_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:04:49 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/25 18:44:18 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_get_float(xmlNodePtr cur, void *ptr, char *name)
{
	xmlChar		*tmp;
	float		*num;

	num = (float*)ptr;
	tmp = xmlGetProp(cur, (xmlChar*)name);
	if (tmp)
	{
		*num = rt_atof((char*)tmp);
		xmlFree(tmp);
	}
}
