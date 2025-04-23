/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 11:02:19 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/23 14:43:26 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*initialisation(int argc, char **argv)
{
	t_stack		*stack_a;
	long int	nb;
	int			index;

	stack_a = NULL;
	nb = 0;
	index = 1;
	while (index < argc)
	{
		nb = ft_atoi(argv[index]);
		if (nb > INT_MAX || nb < INT_MIN || ft_strlen(argv[index]) > 12)
			send_error(&stack_a, NULL);
		if (index == 1)
			stack_a = stack_new((int)nb);
		else
			stack_add_bottom(&stack_a, stack_new((int)nb));
		index++;
	}
	return (stack_a);
}

void	get_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*higgest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		higgest = NULL;
		value = INT_MIN;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				higgest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (higgest != NULL)
			higgest->index = stack_size;
	}
}

int	ft_strlen(const char *str)
{
	int	compteur;

	compteur = 0;
	while (str[compteur])
		compteur++;
	return (compteur);
}
