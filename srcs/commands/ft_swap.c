/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:45:11 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/23 13:57:06 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_swap(t_stack *stack)
{
	int	current;

	if (stack == NULL || stack->next == NULL)
		return ;
	current = stack->value;
	stack->value = stack->next->value;
	stack->next->value = current;
	current = stack->index;
	stack->index = stack->next->index;
	stack->next->index = current;
}

void	sa(t_stack **stack_a)
{
	ft_swap(*stack_a);
	ft_printf("sa\n");
}

void	sb(t_stack **stack_b)
{
	ft_swap(*stack_b);
	ft_printf("sb\n");
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(*stack_a);
	ft_swap(*stack_b);
	ft_printf("ss\n");
}
