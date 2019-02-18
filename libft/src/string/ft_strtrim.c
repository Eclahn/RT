/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:04:18 by juthomas          #+#    #+#             */
/*   Updated: 2016/10/21 14:27:34 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s)
{
	size_t	i;
	char	*str;

	while (*s == ' ' || *s == '\n' || *s == '\t')
		s++;
	if (ft_strlen(s))
	{
		i = ft_strlen(s) - 1;
		while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && i > 0)
			i--;
		if ((str = (char *)malloc(sizeof(char) * (i + 2))) != NULL)
			ft_strcpy(str, ft_strsub(s, 0, (i + 1)));
		return (str);
	}
	return (ft_strdup(s));
}
