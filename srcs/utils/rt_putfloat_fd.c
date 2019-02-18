/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_putfloat_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 01:56:18 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/22 16:58:55 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

/*
**  This fonc need to be verified by Nazis
*/

static void		this_part_two(long int l, int fd)
{
	if (l < 0)
	{
		ft_putchar_fd('-', fd);
		l = -l;
	}
	if (l > 9)
	{
		this_part_two(l / 10, fd);
		this_part_two(l % 10, fd);
	}
	else
	{
		l = l + 48;
		ft_putchar_fd(l, fd);
	}
}

static void		this_part_three(float *nbr, long l, int *precision, int fd)
{
	ft_putchar_fd('.', fd);
	while (*nbr > 0 && (*precision)--)
	{
		(*nbr) = (*nbr) * 10;
		l = (long)(*nbr);
		l = l % 10;
		(*nbr) = (*nbr) - l;
		ft_putchar_fd(l + 48, fd);
	}
}

void			rt_putfloat_fd(float nbr, int fd)
{
	long	l;
	float	r;
	int		precision;

	precision = 10;
	if (nbr < 0 && nbr != INFINITY && nbr != -INFINITY)
	{
		ft_putstr_fd("-", fd);
		nbr = -nbr;
	}
	l = (long)nbr;
	r = 0.5;
	if (nbr == INFINITY || nbr == -INFINITY)
	{
		if (nbr == -INFINITY)
			ft_putstr_fd("-", fd);
		ft_putstr_fd("99999999999", fd);
		return ;
	}
	if ((fabs(nbr - l) >= r) && (precision == 0))
		l = ((l > 0) ? l + 1 : l - 1);
	this_part_two(l, fd);
	nbr = fabs(nbr - l);
	if (nbr > 0 && precision != 0)
		this_part_three(&nbr, l, &precision, fd);
}
