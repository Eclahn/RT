/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 15:50:18 by juthomas          #+#    #+#             */
/*   Updated: 2016/02/02 15:52:44 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int				ft_pwr(int n, int p)
{
	if (p < 0)
		return (0);
	if (p == 0)
		return (1);
	return (n * ft_pwr(n, p - 1));
}