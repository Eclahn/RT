/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_fill_directional.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 21:57:10 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/07 18:26:45 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_fill_directional(xmlNodePtr cur, t_scene *scene, t_num *num,
			char *filename)
{
	scene->light[num->lum].type = L_DIRECTIONAL;
	rt_fill_light(cur->children, &scene->light[num->lum], USED_DIRECTIONAL,
			filename);
	num->lum += 1;
}
