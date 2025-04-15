/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:29:23 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/15 12:59:12 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_target(t_pile *pile_a, t_pile *pile_b)
{
	t_element *current_a;
	t_element *current_b;
	t_element *temp_min;

	current_a = pile_a->first;
	while(current_a)
	{
		if (pile_a->smallest->number <= pile_b->smallest->number)
			temp_min = pile_a->smallest;
		else
			temp_min = pile_b->smallest;
		current_b = pile_b->first;
		while(current_b)
		{
			if (current_a->number < pile_b->smallest->number)
				temp_min = pile_b->biggest;
			if ((current_a->number >= current_b->number) && (temp_min->number < current_b->number))
				temp_min = current_b;
			current_b = current_b->next;
		}
		current_a->target_node = temp_min;
		// printf("Current a : %d | Target current_a : %d\n", current_a->number, current_a->target_node->number);
		current_a = current_a->next;
	}
}
