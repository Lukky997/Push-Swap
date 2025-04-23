/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:40:58 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/23 14:23:25 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	get_position(t_stack **stack)
{
	t_stack	*current;
	int		index;

	current = *stack;
	index = 0;
	while (current)
	{
		current->pos = index;
		current = current->next;
		index++;
	}
}

int	get_lowest_index_position(t_stack **stack)
{
	t_stack	*current;
	int		lowest_index;
	int		lowest_pos;

	current = *stack;
	lowest_index = INT_MAX;
	get_position(stack);
	lowest_pos = current->pos;
	while (current)
	{
		if (current->index < lowest_index)
		{
			lowest_index = current->index;
			lowest_pos = current->pos;
		}
		current = current->next;
	}
	return (lowest_pos);
}

static int	get_target(t_stack **stack_a, int index_b, int target_index,
		int target_pos)
{
	t_stack	*current_a;

	current_a = *stack_a;
	while (current_a)
	{
		if (current_a->index > index_b && current_a->index < target_index)
		{
			target_index = current_a->index;
			target_pos = current_a->pos;
		}
		current_a = current_a->next;
	}
	if (target_index != INT_MAX)
		return (target_pos);
	current_a = *stack_a;
	while (current_a)
	{
		if (current_a->index < target_index)
		{
			target_index = current_a->index;
			target_pos = current_a->pos;
		}
		current_a = current_a->next;
	}
	return (target_pos);
}

void	get_target_position(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current_b;
	int		targer_pos;

	current_b = *stack_b;
	get_position(stack_a);
	get_position(stack_b);
	targer_pos = 0;
	while (current_b)
	{
		targer_pos = get_target(stack_a, current_b->index, INT_MAX, targer_pos);
		current_b->target_pos = targer_pos;
		current_b = current_b->next;
	}
}
