/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_float_min_max.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 00:28:22 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/14 00:37:10 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_float_min_max(float *number, float min, float max)
{
	if (*number < min)
		*number = min;
	if (*number > max)
		*number = max;
}
