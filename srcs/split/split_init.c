/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:08:51 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/23 16:08:01 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*split_init(char **argv)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 0;
	while (argv[i])
	{
		nb = ft_atoi(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN || ft_strlen(argv[i]) > 12)
		{
			free_stack(&stack_a);
			send_error_split(argv);
		}
		if (i == 0)
			stack_a = stack_new((int)nb);
		else
			stack_add_bottom(&stack_a, stack_new((int)nb));
		i++;
	}
	return (stack_a);
}

void	send_error_split(char **result)
{
	free_if_error(result);
	send_error(NULL, NULL);
}
