/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 12:29:12 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/19 14:57:54 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_pile *pile)
{
	int			i;
	t_element	*current;

	i = 0;
	current = pile->first;
	while (current)
	{
		current->index = i;
		current = current->next;
		i++;
	}
}

void	set_above_median(t_pile *pile)
{
	t_element	*current;
	int			median;

	current = pile->first;
	median = pile->nb_element / 2;
	while (current)
	{
		current->above_median = current->index <= median;
		current = current->next;
	}
}

void	calculate_cost(t_pile *pile_a, t_pile *pile_b)
{
	t_element	*current;

	current = pile_a->first;
	while (current)
	{
		current->push_cost = 0;
		if (!current->target_node)
		{
			current = current->next;
			continue;
		}
		if (current->above_median)
			current->push_cost += current->index;
		else
			current->push_cost += pile_a->nb_element - current->index;
		if (current->target_node->above_median)
			current->push_cost += current->target_node->index;
		else
			current->push_cost += pile_b->nb_element
				- current->target_node->index;
		current = current->next;
	}
}


t_element	*find_cheapest(t_pile *pile)
{
	t_element	*current;
	t_element	*cheapest;

	current = pile->first;
	cheapest = current;
	while (current)
	{
		if (current->push_cost < cheapest->push_cost)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}

void	do_cheapest_move(t_pile *pile_a, t_pile *pile_b, int direction)
{
	t_element	*cheapest;

	cheapest = find_cheapest(pile_a);
	do_move(pile_a, pile_b, cheapest, direction);
}
