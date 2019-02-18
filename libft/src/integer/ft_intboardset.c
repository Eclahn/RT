/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intboardset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 20:53:31 by juthomas          #+#    #+#             */
/*   Updated: 2016/10/17 10:03:47 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int			**ft_intboardset(size_t x, size_t y, int c)
{
	int		**rslt;
	size_t	i;
	size_t	j;

	j = 0;
	rslt = (int**)malloc((sizeof(int*) * y) + sizeof(int) * (x * y));
	if (!rslt)
		return (NULL);
	while (j < y)
	{
		i = 0;
		rslt[j] = (int*)rslt + 2 * y + (x * j);
		while (i < x)
		{
			rslt[j][i] = c;
			i++;
		}
		j++;
	}
	return (rslt);
}
