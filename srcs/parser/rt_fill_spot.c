/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_fill_spot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 18:22:42 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/03 03:39:06 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_fill_spot(xmlNodePtr cur, t_scene *scene, t_num *num, char *filename)
{
	scene->light[num->lum].type = L_SPOT;
	rt_fill_light(cur->children, &scene->light[num->lum], USED_SPOT, filename);
	num->lum += 1;
}
