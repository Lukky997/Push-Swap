/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:34:27 by lgoras            #+#    #+#             */
/*   Updated: 2025/02/27 15:22:53 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    fill_a(t_pile *pile_a, char **argv);

int	main(int argc, char **argv)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
	{
		printf("pas bon");
		return (0);
	}
	else if (argc == 2)
		ft_split(argv[1], ' ');
	pile_a = initialisation();
	pile_b = initialisation();
	printf("ok\n");
	fill_a(pile_a, argv);
	if (pile_sorted(pile_a))
		printf("pile trie\n");
	if(!pile_sorted(pile_a))
	{
		printf("la pile n'est pas trie");
		if (pile_a->nb_element == 3)
			sort_three(pile_a);
		if (pile_a->nb_element == 2)
			sa(pile_a);
		// else
		// 	push_swap(&pile_a, &pile_b);
	}
	// free_stack(&pile_a);
	return (0);
}

void fill_a(t_pile *pile_a, char **argv)
{
    int i = 1;
    while (argv[i])
    {
        empiler(pile_a, atoi(argv[i]));
        i++;
    }
}


int len_a(t_pile *pile_a)
{
    int index = 0;
    t_element *current = pile_a->first;
    while (current)
    {
        index++;
        current = current->next;
    }
    return index;
}
