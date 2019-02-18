/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_get_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 21:14:32 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/10 03:53:06 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_get_path(xmlNodePtr cur, void *ptr, char *name)
{
	char	**str;
	int		i;

	i = 0;
	str = (char**)ptr;
	(void)name;
	while (i < TEXTURE_ALL)
	{
		rt_get_string(cur, &str[i], g_texture[i].name);
		i++;
	}
}
