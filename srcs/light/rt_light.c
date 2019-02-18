/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_light.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/03 20:38:11 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/28 20:21:33 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

void	rt_light(const t_object *object, const t_light *light,
			t_refl_refr *ref, const t_float3 *vector)
{
	t_float3	kolor;
	float		alpha;

	alpha = rt_vector_dot_p(&ref->normal, &ref->light);
	if (alpha > 0)
	{
		rt_float3_mult_float(&ref->kd, 1 - object->transparency, &kolor);
		rt_light_diffuse(&kolor, &light->luminance, alpha,
			&ref->color);
		ref->normal_h = (t_float3){.x = ref->light.x - vector->x,
			.y = ref->light.y - vector->y, .z = ref->light.z - vector->z};
		rt_vector_normalize(&ref->normal_h);
		alpha = powf(rt_vector_dot_p(&ref->normal, &ref->normal_h), object->ns);
		rt_light_diffuse(&ref->ks, &light->luminance, alpha,
			&ref->color);
	}
}
