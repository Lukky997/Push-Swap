/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:09:16 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/19 14:48:22 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pile_sorted(t_pile *pile)
{
	t_element	*current;

	if (!pile || !pile->first)
		return (1);
	current = pile->first;
	while (current->next)
	{
		if (current->number > current->next->number)
			return (0);
		current = current->next;
	}
	return (1);
}

void	push_swap(t_pile *pile_a, t_pile *pile_b)
{
	t_element	*current_a;
	t_element	*current_b;

	current_a = pile_a->first;
	current_b = pile_b->first;
	pb(pile_b, pile_a);
	pb(pile_b, pile_a);

	while (pile_a->nb_element > 3)
	{
		find_smallest_and_biggest(pile_a, pile_b);
		set_index(pile_a);
		set_index(pile_b);
		set_above_median(pile_a);
		set_above_median(pile_b);
		find_target(pile_a, pile_b);
		calculate_cost(pile_a, pile_b);
		do_cheapest_move(pile_a, pile_b, 0);
	}
	sort_three(pile_a);
	finish_sort(pile_a, pile_b);
	rotate_to_min_top(pile_a);
}
