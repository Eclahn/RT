/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_get_float4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:05:28 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/07 18:33:52 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_get_float4(xmlNodePtr cur, void *ptr, char *name)
{
	t_float4		*num;
	static char		tmp[2];

	tmp[1] = '\0';
	num = ptr;
	tmp[0] = name[0];
	rt_get_float(cur, &num->w, tmp);
	tmp[0] = name[1];
	rt_get_float(cur, &num->x, tmp);
	tmp[0] = name[2];
	rt_get_float(cur, &num->y, tmp);
	tmp[0] = name[3];
	rt_get_float(cur, &num->z, tmp);
}
