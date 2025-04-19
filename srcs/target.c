/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:29:23 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/19 14:54:14 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target(t_pile *pile_a, t_pile *pile_b)
{
	t_element	*current_a;
	t_element	*current_b;
	t_element	*best_target;

	current_a = pile_a->first;
	if(!pile_b->first)
		return ;
	while (current_a)
	{
		best_target = NULL;
		current_b = pile_b->first;
		while(current_b)
		{
			if(current_a->number < current_b->number)
			{
				if(!best_target || current_b->number < best_target->number)
					best_target = current_b;
			}
			current_b = current_b->next;
		}
		if (!best_target)
			best_target = pile_b->smallest;
		current_a->target_node = best_target;
		current_a = current_a->next;
	}
}
