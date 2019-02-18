/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_noise_val.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 19:20:51 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/29 03:17:17 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		this_noise(t_float3 gradients[4], t_float3 integral)
{
	(gradients)[0] = g_gradients[g_permutation[
		g_permutation[(int)integral.x] + (int)(integral.y)] % 8];
	(gradients)[1] = g_gradients[g_permutation[
		g_permutation[(1 + (int)integral.x) % 16] + (int)(integral.y)] % 8];
	(gradients)[2] = g_gradients[g_permutation[
		g_permutation[(int)integral.x] + (1 + (int)(integral.y) % 16)] % 8];
	(gradients)[3] = g_gradients[g_permutation[
		g_permutation[(1 + (int)integral.x) % 16]
		+ (1 + (int)(integral.y) % 16)] % 8];
}

float			noise(float x, float y)
{
	t_float3	integral;
	t_float3	fract;
	t_float3	faded;
	t_float3	to_center[4];
	t_float3	gradients[4];

	integral.x = (int)x & 15;
	integral.y = (int)y & 15;
	fract.x = x - (int)x;
	fract.y = y - (int)y;
	to_center[0] = (t_float3){.x = fract.x, .y = fract.y, .z = 0};
	to_center[1] = (t_float3){.x = fract.x - 1, .y = fract.y, .z = 0};
	to_center[2] = (t_float3){.x = fract.x, .y = fract.y - 1, .z = 0};
	to_center[3] = (t_float3){.x = fract.x - 1, .y = fract.y - 1, .z = 0};
	faded.x = fade(fract.x);
	faded.y = fade(fract.y);
	this_noise(gradients, integral);
	return (0.5 * (1 + (0.507 * (lerp(lerp(rt_vector_dot_p(
		&to_center[0], &gradients[0]),
	rt_vector_dot_p(&to_center[1], &gradients[1]), faded.x),
	lerp(rt_vector_dot_p(&to_center[2], &gradients[2]),
	rt_vector_dot_p(&to_center[3], &gradients[3]), faded.x), faded.y)))));
}

float			octave(float x, float y, int octaves, float persistence)
{
	float	total;
	float	frequency;
	float	amplitude;
	float	maxvalue;
	int		i;

	i = 0;
	total = 0;
	frequency = 1;
	amplitude = 1;
	maxvalue = 0;
	while (i < octaves)
	{
		total += noise(x * frequency, y * frequency) * amplitude;
		maxvalue += amplitude;
		amplitude *= persistence;
		frequency *= 2;
		i++;
	}
	return (total / maxvalue);
}
