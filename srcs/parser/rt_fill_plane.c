/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_fill_plane.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 20:06:48 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/07 18:30:17 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_fill_plane(xmlNodePtr cur, t_scene *scene, t_num *num,
			char *filename)
{
	scene->object[num->obj].type = PLANE;
	rt_fill_object(cur->children, &scene->object[num->obj], USED_PLANE,
			filename);
	num->obj += 1;
}
