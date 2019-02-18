/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 02:28:32 by juthomas          #+#    #+#             */
/*   Updated: 2016/10/21 14:29:18 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_words(char const *s, char c)
{
	size_t	w;

	w = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		while (*s != c && *s)
			s++;
		w++;
	}
	return (w);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	int		n;
	char	**rslt;

	n = 0;
	if ((rslt = (char **)malloc(sizeof(char *) * (ft_words(s, c) + 1))) == NULL)
		return (NULL);
	while (*s)
	{
		i = 0;
		while (*s == c)
			s++;
		while (s[i] != c && s[i])
			i++;
		if ((s[i] == '\0' || s[i] == c) && i)
			rslt[n++] = ft_strncpy(ft_strnew(i + 1), s, i);
		s += i;
	}
	rslt[n] = NULL;
	return (rslt);
}
