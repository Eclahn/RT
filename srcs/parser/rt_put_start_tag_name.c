/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_put_start_tag_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:15:43 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/21 19:07:14 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_put_start_tag_name(char *type, char *name, int indent, int fd)
{
	while (indent-- > 0)
		ft_putstr_fd("\t", fd);
	ft_putstr_fd("<", fd);
	ft_putstr_fd(type, fd);
	if (name && ft_strcmp(name, ""))
	{
		ft_putstr_fd(" name=\"", fd);
		ft_putstr_fd(name, fd);
		ft_putstr_fd("\"", fd);
	}
	ft_putstr_fd(">\n", fd);
}
