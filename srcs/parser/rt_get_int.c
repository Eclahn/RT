/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_get_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 20:25:20 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/07 18:33:28 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_get_int(xmlNodePtr cur, void *ptr, char *name)
{
	xmlChar *tmp;
	int		*num;

	num = (int*)ptr;
	tmp = xmlGetProp(cur, (xmlChar*)name);
	if (tmp)
	{
		*num = ft_atoi((char*)tmp);
		xmlFree(tmp);
	}
}
