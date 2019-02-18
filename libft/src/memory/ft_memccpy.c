/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 16:28:49 by juthomas          #+#    #+#             */
/*   Updated: 2016/10/17 10:16:33 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
	{
		*((unsigned char *)dst) = *((const unsigned char *)src);
		dst = (char*)dst + 1;
		src = (const char*)src + 1;
		if (*((const unsigned char *)src - 1) == (unsigned char)c)
			return (dst);
	}
	return (NULL);
}
