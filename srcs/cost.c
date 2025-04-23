/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:23:17 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/23 14:23:34 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_cost(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_a;
	t_stack	*current_b;
	int		size_a;
	int		size_b;

	current_a = *stack_a;
	current_b = *stack_b;
	size_a = stack_len(current_a);
	size_b = stack_len(current_b);
	while (current_b)
	{
		current_b->cost_b = current_b->pos;
		if (current_b->pos > size_b / 2)
			current_b->cost_b = (size_b - current_b->pos) * -1;
		current_b->cost_a = current_b->target_pos;
		if (current_b->target_pos > size_a / 2)
			current_b->cost_a = (size_a - current_b->target_pos) * -1;
		current_b = current_b->next;
	}
}

void	do_cheapest_move(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	int		cheapest;
	int		cost_a;
	int		cost_b;

	current = *stack_b;
	cheapest = INT_MAX;
	while (current)
	{
		if (nb_abs(current->cost_a)
			+ nb_abs(current->cost_b) < nb_abs(cheapest))
		{
			cheapest = nb_abs(current->cost_b) + nb_abs(current->cost_a);
			cost_a = current->cost_a;
			cost_b = current->cost_b;
		}
		current = current->next;
	}
	do_move(stack_a, stack_b, cost_a, cost_b);
}
