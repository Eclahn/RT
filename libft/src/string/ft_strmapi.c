/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 10:47:08 by juthomas          #+#    #+#             */
/*   Updated: 2016/10/17 11:02:25 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*rslt;
	size_t	i;

	i = ft_strlen(s);
	if ((rslt = (char *)malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	rslt[i] = '\0';
	while (i--)
		rslt[i] = (*f)((unsigned int)i, s[i]);
	return (rslt);
}
