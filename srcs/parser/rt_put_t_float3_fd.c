/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_put_t_float3_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:08:28 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/21 19:14:44 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		this_put_t_flaot3_fd(t_float3 *value, char *vname, int fd)
{
	if (value->y != -INFINITY && value->y != INFINITY)
	{
		ft_putstr_fd(" ", fd);
		ft_putchar_fd(vname[1], fd);
		ft_putstr_fd("=\"", fd);
		rt_putfloat_fd(value->y, fd);
		ft_putstr_fd("\"", fd);
	}
	if (value->z != -INFINITY && value->z != INFINITY)
	{
		ft_putstr_fd(" ", fd);
		ft_putchar_fd(vname[2], fd);
		ft_putstr_fd("=\"", fd);
		rt_putfloat_fd(value->z, fd);
		ft_putstr_fd("\"", fd);
	}
	ft_putstr_fd("/>\n", fd);
}

void			rt_put_t_float3_fd(void *ptr, char *vname, char *tname, int fd)
{
	t_float3	*value;
	int			indent;

	value = ptr;
	indent = 3;
	if (!vname || ft_strlen(vname) < 3)
		rt_error(ERROR_DEF_SAVE, "output.xml", 0, "undetected value name");
	while (indent-- > 0)
		ft_putstr_fd("\t", fd);
	ft_putstr_fd("<", fd);
	ft_putstr_fd(tname, fd);
	if (value->x != -INFINITY && value->x != INFINITY)
	{
		ft_putstr_fd(" ", fd);
		ft_putchar_fd(vname[0], fd);
		ft_putstr_fd("=\"", fd);
		rt_putfloat_fd(value->x, fd);
		ft_putstr_fd("\"", fd);
	}
	this_put_t_flaot3_fd(value, vname, fd);
}
