/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 20:33:14 by juthomas          #+#    #+#             */
/*   Updated: 2016/10/17 10:36:05 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;

	if (*s2)
	{
		while (*s1)
		{
			i = 0;
			while (s1[i] == s2[i])
			{
				if (!s2[++i])
					return ((char *)(unsigned long)s1);
			}
			s1++;
		}
		return (NULL);
	}
	return ((char *)(unsigned long)s1);
}
