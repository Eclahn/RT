/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_fill_sphere.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 20:07:27 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/07 18:31:29 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_fill_sphere(xmlNodePtr cur, t_scene *scene, t_num *num,
			char *filename)
{
	scene->object[num->obj].type = SPHERE;
	rt_fill_object(cur->children, &scene->object[num->obj],
			USED_SPHERE, filename);
	num->obj += 1;
}
