/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 01:38:46 by juthomas          #+#    #+#             */
/*   Updated: 2016/10/17 10:28:21 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_atoi_base(const char *str, size_t base)
{
	size_t		rslt;
	size_t		temp;

	rslt = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	while (*str)
	{
		temp = 126;
		if ((*str >= '0' && *str <= '0' + (int)base - 1) && base <= 10)
			temp = (size_t)(*str - 48);
		if ((*str >= '0' && *str <= '9') && base > 10)
			temp = (size_t)(*str - 48);
		if ((*str >= 'A' && *str <= 'A' + (int)base - 11) && base <= 36)
			temp = (size_t)(*str - 55);
		if ((*str >= 'a' && *str <= 'a' + (int)base - 11) && base <= 36)
			temp = (size_t)(*str - 87);
		if (temp != 126)
			rslt = rslt * base + temp;
		else
			return (rslt);
		str++;
	}
	return (rslt);
}
