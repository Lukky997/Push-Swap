/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   biggest_and_smallest.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:53:00 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/19 12:40:53 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_smallest_and_biggest(t_pile *pile_a, t_pile *pile_b)
{
	t_element	*current_a;
	t_element	*current_b;

	current_a = pile_a->first;
	current_b = pile_b->first;
	pile_a->biggest = current_a;
	pile_a->smallest = current_a;
	pile_b->biggest = current_b;
	pile_b->smallest = current_b;
	while (current_a)
	{
		if (current_a->number > pile_a->biggest->number)
			pile_a->biggest = current_a;
		if (current_a->number < pile_a->smallest->number)
			pile_a->smallest = current_a;
		current_a = current_a->next;
	}
	while (current_b)
	{
		if (current_b->number > pile_b->biggest->number)
			pile_b->biggest = current_b;
		if (current_b->number < pile_b->smallest->number)
			pile_b->smallest = current_b;
		current_b = current_b->next;
	}
}
