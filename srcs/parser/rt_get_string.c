/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_get_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:04:31 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/10 03:51:01 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_get_string(xmlNodePtr cur, void *ptr, char *name)
{
	xmlChar *tmp;
	char	**str;

	str = (char**)ptr;
	*str = NULL;
	tmp = xmlGetProp(cur, (xmlChar*)name);
	if (tmp)
	{
		if (xmlStrcmp(tmp, (xmlChar*)""))
		{
			*str = (char*)ft_strdup((char*)tmp);
			if (*str == NULL)
				rt_error(ERROR_MALLOC, __FILE__, __LINE__, "");
		}
		xmlFree(tmp);
	}
}
