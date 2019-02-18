/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 02:28:53 by juthomas          #+#    #+#             */
/*   Updated: 2016/10/17 09:55:57 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		s;

	s = 1;
	if (n < 0)
	{
		s = -1;
		ft_putchar_fd('-', fd);
	}
	if (n < -9 || n > 9)
		ft_putnbr_fd((n / 10) * s, fd);
	ft_putchar_fd((char)(n % 10 * s + '0'), fd);
	s = 1;
}
