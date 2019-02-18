/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_first_noticeable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 00:36:05 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/23 19:30:40 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

int	rt_first_noticeable(t_visible *v1, t_impact *i2, int id)
{
	t_visible	v2;

	rt_impact_to_visible(i2, &v2, id);
	if (v1->visible >= 0 && v2.visible >= 0)
	{
		if (v1->k >= v2.k)
		{
			*v1 = v2;
			return (1);
		}
	}
	else if (v1->visible >= 0)
		;
	else if (v2.visible >= 0)
	{
		*v1 = v2;
		return (1);
	}
	else
		*v1 = (t_visible){.visible = -1, .k = -1};
	return (0);
}
