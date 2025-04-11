/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:34:27 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/11 12:36:53 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_a(t_pile *pile_a, char **argv);

int	main(int argc, char **argv)
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	char	**numbers;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (0);
	if (argc == 2)
		numbers = ft_split(argv[1], ' ');
	else
		numbers = argv + 1;
	pile_a = initialisation();
	pile_b = initialisation();
	printf("ok\n");
	fill_a(pile_a, numbers);
	if (argc == 2)
		free_split(numbers);
	afficher_pile(pile_a);
	if (!pile_sorted(pile_a))
	{
		if (pile_a->nb_element == 3)
			sort_three(pile_a);
		else if (pile_a->nb_element == 2)
			sa(pile_a);
		else
			push_swap(&pile_a, &pile_b);
	}
	afficher_pile(pile_a);
	suppression(pile_a);
	free(pile_b);
	return (0);
}

void	fill_a(t_pile *pile_a, char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i])
	{
		empiler(pile_a, atoi(numbers[i]));
		i++;
	}
}

int	len_a(t_pile *pile_a)
{
	int			index;
	t_element	*current;

	index = 0;
	current = pile_a->first;
	while (current)
	{
		index++;
		current = current->next;
	}
	return (index);
}
