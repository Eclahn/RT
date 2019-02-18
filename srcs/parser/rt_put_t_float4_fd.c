/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_put_t_float4_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:06:58 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/21 19:22:23 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		this_vive_la_norme(t_float3 convert, int fd)
{
	rt_putfloat_fd(convert.z, fd);
	ft_putstr_fd("\"/>\n", fd);
}

void			rt_put_t_float4_fd(void *ptr, char *vname, char *tname, int fd)
{
	t_float4	*value;
	t_float3	convert;
	int			indent;

	value = ptr;
	indent = 3;
	if (!vname || ft_strlen(vname) < 4)
		rt_error(ERROR_DEF_SAVE, "output.xml", 0, "undetected value name");
	while (indent-- > 0)
		ft_putstr_fd("\t", fd);
	rt_quaternion_to_euler(&convert.x, &convert.y, &convert.z, value);
	ft_putstr_fd("<", fd);
	ft_putstr_fd(tname, fd);
	ft_putstr_fd(" ", fd);
	ft_putchar_fd(vname[1], fd);
	ft_putstr_fd("=\"", fd);
	rt_putfloat_fd(convert.x, fd);
	ft_putstr_fd("\" ", fd);
	ft_putchar_fd(vname[2], fd);
	ft_putstr_fd("=\"", fd);
	rt_putfloat_fd(convert.y, fd);
	ft_putstr_fd("\" ", fd);
	ft_putchar_fd(vname[3], fd);
	ft_putstr_fd("=\"", fd);
	this_vive_la_norme(convert, fd);
}
