/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:34:27 by lgoras            #+#    #+#             */
/*   Updated: 2025/02/12 13:34:29 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	pile_a = NULL;
	pile_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return(1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	init_stack_a(&pile_a, argv + 1);
	if (!stack_sorted(pile_a))
	{
		if (stack_len(pile_a) == 2)
			sa(&pile_a);
		else if (stack_len(pile_a) == 3)
			short_three(&pile_a);
		else
			short_stacks(&pile_a, &pile_b);
	}
	free_stack(&pile_a);
	return(0);
}
