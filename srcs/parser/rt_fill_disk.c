/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_fill_disk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 20:08:57 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/07 18:27:33 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	rt_fill_disk(xmlNodePtr cur, t_scene *scene, t_num *num, char *filename)
{
	scene->object[num->obj].type = DISK;
	rt_fill_object(cur->children, &scene->object[num->obj],
			USED_DISK, filename);
	num->obj += 1;
}
