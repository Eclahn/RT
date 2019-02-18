/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_put_string_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:09:12 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/21 19:11:48 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_put_string_fd(void *ptr, char *vname, char *tname, int fd)
{
	char		**value;
	int			indent;

	value = (char**)ptr;
	indent = 3;
	if (!vname || ft_strlen(vname) < 1)
		rt_error(ERROR_DEF_SAVE, "output.xml", 0, "undetected value name");
	while (indent-- > 0)
		ft_putstr_fd("\t", fd);
	ft_putstr_fd("<", fd);
	ft_putstr_fd(tname, fd);
	ft_putstr_fd(" ", fd);
	ft_putstr_fd(vname, fd);
	ft_putstr_fd("=\"", fd);
	ft_putstr_fd(*value, fd);
	ft_putstr_fd("\"/>\n", fd);
}
