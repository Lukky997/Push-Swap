/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:50:17 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/23 14:24:42 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_highest_index(t_stack *stack)
{
	int	current;

	current = stack->index;
	while (stack)
	{
		if (stack->index > current)
			current = stack->index;
		stack = stack->next;
	}
	return (current);
}

void	sort_three(t_stack **stack)
{
	int	highest;

	if (stack_sorted(*stack))
		return ;
	highest = find_highest_index(*stack);
	if ((*stack)->index == highest)
		ra(stack);
	else if ((*stack)->next->index == highest)
		rra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

static void	push_until_is_three(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;
	int	pushed;
	int	index;

	stack_size = stack_len(*stack_a);
	pushed = 0;
	index = 0;
	while (stack_size > 6 && index < stack_size && pushed < stack_size / 2)
	{
		if ((*stack_a)->index <= stack_size / 2)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
			ra(stack_a);
		index++;
	}
	while ((stack_size - pushed) > 3)
	{
		pb(stack_a, stack_b);
		pushed++;
	}
}

static void	move_min_to_top(t_stack **stack_a)
{
	int	lowest_pos;
	int	stack_size;

	stack_size = stack_len(*stack_a);
	lowest_pos = get_lowest_index_position(stack_a);
	if (lowest_pos > (stack_size / 2))
	{
		while (lowest_pos < stack_size)
		{
			rra(stack_a);
			lowest_pos++;
		}
	}
	else
	{
		while (lowest_pos > 0)
		{
			ra(stack_a);
			lowest_pos--;
		}
	}
}

void	sort(t_stack **stack_a, t_stack **stack_b)
{
	push_until_is_three(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		get_target_position(stack_a, stack_b);
		get_cost(stack_a, stack_b);
		do_cheapest_move(stack_a, stack_b);
	}
	if (!stack_sorted(*stack_a))
		move_min_to_top(stack_a);
}
