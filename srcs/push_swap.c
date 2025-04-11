/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:09:16 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/11 12:56:47 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pile_sorted(t_pile *pile)
{
	t_element	*current;

	if (!pile || !pile->first)
		return (1);
	current = pile->first;
	while (current->next)
	{
		if (current->number > current->next->number)
			return (0);
		current = current->next;
	}
	return (1);
}

void	sort_three(t_pile *pile)
{
	t_element	*current;

	if (!pile || !pile->first || !pile->first->next || !pile->first->next->next)
		return ;
	current = pile->first;
	if (current->number > current->next->number
		&& current->number > current->next->next->number)
		ra(pile);
	else if (current->next->number > current->number
		&& current->next->number > current->next->next->number)
		rra(pile);
	if (pile->first->number > pile->first->next->number)
		sa(pile);
}

void	push_swap(t_pile *pile_a, t_pile *pile_b)
{
	t_element *current_a;
	t_element *current_b;

	pb(pile_b, pile_a);
	pb(pile_b, pile_a);
	while (!pile_sorted(pile_a) && pile_b->nb_element > 0)
	{
		find_target(pile_a, pile_b);
	}
}

void	find_target(t_pile *pile_a, t_pile *pile_b)
{
	find_smallest_and_biggest(pile_a, pile_b);
	
}
