/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:28:38 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/19 16:26:58 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_move(t_pile *pile_a, t_pile *pile_b, t_element *cheapest,
		int direction)
{
	if (!cheapest)
		return ;
	while (pile_a->first != cheapest && pile_b->first != cheapest->target_node)
	{
		if (cheapest->above_median && cheapest->target_node->above_median)
			rr(pile_a, pile_b);
		else if (!cheapest->above_median
			&& !cheapest->target_node->above_median)
			rrr(pile_a, pile_b);
		else
			break ;
	}
	while (pile_a->first != cheapest)
	{
		if (cheapest->above_median)
			ra(pile_a);
		else
			rra(pile_a);
	}
	while (pile_b->first != cheapest->target_node)
	{
		if (cheapest->target_node->above_median)
			rb(pile_b);
		else
			rrb(pile_b);
	}
	if (direction == 0)
		pb(pile_b, pile_a);
	else
		pa(pile_a, pile_b);
}

void	rotate_to_min_top(t_pile *pile_a)
{
	t_element	*current;
	t_element	*min;
	int			index;
	int			i;

	current = pile_a->first;
	min = current;
	index = 0;
	i = 0;
	while (current)
	{
		if (current->number < min->number)
		{
			min = current;
			index = i;
		}
		current = current->next;
		i++;
	}
	if (index <= pile_a->nb_element / 2)
	{
		while (pile_a->first != min)
			ra(pile_a);
	}
	else
	{
		while (pile_a->first != min)
			rra(pile_a);
	}
}

void	finish_sort(t_pile *pile_a, t_pile *pile_b)
{
	while (pile_b->nb_element > 0)
	{
		find_smallest_and_biggest(pile_a, pile_b);
		set_index(pile_a);
		set_index(pile_b);
		set_above_median(pile_a);
		set_above_median(pile_b);
		find_target(pile_a, pile_b);
		calculate_cost(pile_b, pile_a);
		do_cheapest_move(pile_a, pile_b, 1);
	}
}
