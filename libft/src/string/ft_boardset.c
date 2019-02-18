/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boardset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 02:01:04 by juthomas          #+#    #+#             */
/*   Updated: 2016/10/21 14:32:08 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_boardset(size_t x, size_t y, char c)
{
	char	**rslt;
	size_t	i;
	size_t	j;

	j = 0;
	rslt = (char**)malloc((sizeof(char*) * y) + (x * y));
	if (!rslt)
		return (NULL);
	while (j < y)
	{
		i = 0;
		rslt[j] = (char*)((char*)rslt) + y * sizeof(char*) + x * j;
		while (i < x)
		{
			rslt[j][i] = c;
			i++;
		}
		j++;
	}
	return (rslt);
}
