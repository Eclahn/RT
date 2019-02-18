/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_list_queue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juthomas <juthomas@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 21:51:23 by juthomas          #+#    #+#             */
/*   Updated: 2018/06/25 19:22:39 by juthomas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_list	**rt_list_queue(int i, int thread)
{
	static t_list *start[NUM_THREAD];
	static t_list *end[NUM_THREAD];

	if (i == 1)
		return (&end[thread]);
	return (&start[thread]);
}
