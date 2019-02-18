/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_impact_to_visible.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 02:23:22 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/23 17:30:17 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	rt_impact_to_visible(t_impact *cldr, t_visible *view, int id)
{
	*view = (t_visible){.visible = -1, .k = -1};
	if (cldr->hit & TRUE)
	{
		if (cldr->k1 > EPSILON && (cldr->hit & K1))
			view->k = cldr->k1;
		if (cldr->k2 > EPSILON && (cldr->hit & K2))
		{
			if (view->k < 0 || (view->k >= 0 && cldr->k2 < view->k))
				view->k = cldr->k2;
		}
		if (view->k >= 0)
			view->visible = id;
	}
}
