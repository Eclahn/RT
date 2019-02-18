/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_init_origin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 17:33:05 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/23 17:35:28 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

static int	this_init_memory(size_t num_obj, t_float3 **origin)
{
	static size_t n_obj;

	if (n_obj != num_obj)
	{
		if (*origin)
			free(*origin);
		n_obj = num_obj;
		if (num_obj > 0)
		{
			if (!(*origin = (t_float3*)malloc(sizeof(t_float3) * num_obj)))
				return (-1);
			return (0);
		}
		return (-1);
	}
	return (0);
}

t_float3	*rt_init_origin(t_float3 *ori, t_object *obj, size_t num_obj)
{
	static t_float3 *origin;

	if (this_init_memory(num_obj, &origin))
		return (NULL);
	while (num_obj-- > 0)
		rt_origin_object(ori, &obj[num_obj], &origin[num_obj]);
	return (origin);
}
