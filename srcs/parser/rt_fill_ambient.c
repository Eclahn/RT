/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_fill_ambient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 20:05:44 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/07 18:22:36 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_fill_ambient(xmlNodePtr cur, t_scene *scene, t_num *num,
			char *filename)
{
	scene->ambient.type = L_AMBIENT;
	rt_fill_light(cur->children, &scene->ambient, USED_AMBIENT, filename);
	num->amb += 1;
}
