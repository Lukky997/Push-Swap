/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:34:27 by lgoras            #+#    #+#             */
/*   Updated: 2025/02/26 17:58:38 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		ft_split(argv[1], ' ');
	pile_a = initialisation();
	pile_b = initialisation();
	if(!pile_sorted(pile_a))
	{
		// if (pile_a->nb_element == 3)
		// 	sort_three(pile_a);
		if (pile_a->nb_element == 2)
			sa(pile_a);
		// else
		// 	push_swap(&pile_a, &pile_b);
	}
	// free_stack(&pile_a);
	return (0);
}
