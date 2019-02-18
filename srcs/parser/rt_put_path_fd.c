/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_put_path_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:09:56 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/21 19:07:50 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_put_path_fd(void *ptr, char *vname, char *tname, int fd)
{
	char		**value;
	int			indent;
	int			i;

	value = (char **)ptr;
	indent = 3;
	(void)vname;
	while (indent-- > 0)
		ft_putstr_fd("\t", fd);
	ft_putstr_fd("<", fd);
	ft_putstr_fd(tname, fd);
	i = 0;
	while (i < TEXTURE_ALL)
	{
		if (value[i] && ft_strcmp(value[i], ""))
		{
			ft_putstr_fd(" ", fd);
			ft_putstr_fd(g_texture[i].name, fd);
			ft_putstr_fd("=\"", fd);
			ft_putstr_fd(value[i], fd);
			ft_putstr_fd("\"", fd);
		}
		i++;
	}
	ft_putstr_fd("/>\n", fd);
}
