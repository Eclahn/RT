/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_fill_cylinder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 20:08:00 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/07 18:25:23 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_fill_cylinder(xmlNodePtr cur, t_scene *scene, t_num *num,
			char *filename)
{
	scene->object[num->obj].type = CYLINDER;
	rt_fill_object(cur->children, &scene->object[num->obj], USED_CYLINDER,
			filename);
	num->obj += 1;
}
