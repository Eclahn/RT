/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_put_end_tag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 14:16:42 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/21 14:26:29 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_put_end_tag(char *type, int indent, int fd)
{
	while (indent-- > 0)
		ft_putstr_fd("\t", fd);
	ft_putstr_fd("</", fd);
	ft_putstr_fd(type, fd);
	ft_putstr_fd(">\n", fd);
}
