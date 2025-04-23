/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:34:27 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/23 15:34:23 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !stack_sorted(*stack_a))
		sa(stack_a);
	else if (stack_size == 3)
		sort_three(stack_a);
	else if (stack_size > 3 && !stack_sorted(*stack_a))
		sort(stack_a, stack_b);
}

void	call_function(t_stack *stack_a, t_stack *stack_b, int stack_size)
{
	get_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	char	**result;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		result = ft_split(argv[1], ' ');
		if (!good_split(result))
			send_error_split(result);
		stack_a = split_init(result);
		free_if_error(result);
	}
	else
	{
		if (!is_correct_input(argv))
			send_error(NULL, NULL);
		stack_a = initialisation(argc, argv);
	}
	stack_b = NULL;
	stack_size = stack_len(stack_a);
	call_function(stack_a, stack_b, stack_size);
	return (0);
}
