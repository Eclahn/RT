/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_fill_cone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 20:08:30 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/07 18:23:10 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_fill_cone(xmlNodePtr cur, t_scene *scene, t_num *num, char *filename)
{
	scene->object[num->obj].type = CONE;
	rt_fill_object(cur->children, &scene->object[num->obj],
					USED_CONE, filename);
	num->obj += 1;
}
