/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:09:16 by lgoras            #+#    #+#             */
/*   Updated: 2025/02/27 15:26:50 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pile_sorted(t_pile *pile)
{
	t_element	*current_a;

    if (!pile || !pile->first)
		return (1);
	current_a = pile->first;
	while (current_a->next)
	{
		if (current_a->number > current_a->next->number)
			return (0);
		current_a = current_a->next;
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

// void	push_swap(t_pile *pile_a, t_pile *pile_b)
// {
// 	t_element *current_a;
// 	t_element *current_b;

// 	pb(pile_b, pile_a);
// 	pb(pile_b, pile_a);
// 	while (!pile_sorted(pile_a))
// 	{}
// }