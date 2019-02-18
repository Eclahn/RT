/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrtostr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 05:01:17 by juthomas          #+#    #+#             */
/*   Updated: 2016/02/24 09:15:26 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_wstrtostr(wchar_t *str)
{
	char	*out;
	char	*tmp1;
	char	*tmp2;

	out = ft_strnew(0);
	while (*str)
	{
		tmp1 = ft_wtoc(*str);
		if (tmp1 == NULL)
		{
			ft_strdel(&out);
			return (NULL);
		}
		tmp2 = ft_strjoin(out, tmp1);
		ft_strdel(&tmp1);
		ft_strdel(&out);
		out = tmp2;
		str++;
	}
	return (out);
}
