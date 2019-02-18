/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_apply_limits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/28 07:18:45 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/23 17:27:27 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

inline static int	this_custom_limits(float x, float min, float max)
{
	if (min <= max && min < x && x < max)
		return (TRUE);
	else if (min >= max && !(min > x && x > max))
		return (TRUE);
	else
		return (FALSE);
}

inline static int	this_inside_limits(int limit, t_float3 *k,
						const t_float3 *min, const t_float3 *max)
{
	if ((((limit & LIMIT_X) && this_custom_limits(k->x, min->x, max->x)
			== TRUE)
		|| !(limit & LIMIT_X))
		&& ((limit & LIMIT_Y && this_custom_limits(k->y, min->y, max->y)
			== TRUE)
		|| !(limit & LIMIT_Y))
		&& ((limit & LIMIT_Z && this_custom_limits(k->z, min->z, max->z)
			== TRUE)
		|| !(limit & LIMIT_Z)))
		return (TRUE);
	else
		return (FALSE);
}

void				rt_apply_limits(const t_object *object, t_impact *impact,
						t_float3 *ray, t_float3 *origin)
{
	t_float3 k1;
	t_float3 k2;

	if (impact->hit & TRUE)
	{
		if (object->limit & TRUE)
		{
			k1 = rt_vector_impact(origin, ray, impact->k1);
			k2 = rt_vector_impact(origin, ray, impact->k2);
			if (this_inside_limits(object->limit, &k1, &object->limit_min,
				&object->limit_max) == TRUE)
				impact->hit |= K1;
			if (this_inside_limits(object->limit, &k2, &object->limit_min,
				&object->limit_max) == TRUE)
				impact->hit |= K2;
		}
		else
			impact->hit |= (K1 | K2);
	}
}
