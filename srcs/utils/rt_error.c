/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 18:27:03 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/23 19:24:08 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_error(int error, const char *file, const int line, const char *str)
{
	if (error > 0 && error < ERROR_ALL)
	{
		if (file)
			ft_putstr_fd(file, FD_ERROR);
		if (line)
			ft_putnbr_fd(line, FD_ERROR);
		ft_putstr_fd(g_error[error], FD_ERROR);
		if (str)
			ft_putstr_fd(str, FD_ERROR);
		ft_putchar_fd('\n', FD_ERROR);
		if (error < ERROR_EXIT)
			exit(-1);
	}
}
