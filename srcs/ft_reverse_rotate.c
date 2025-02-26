/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:49:50 by lgoras            #+#    #+#             */
/*   Updated: 2025/02/26 17:35:05 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_pile *pile)
{
	t_element	*temp;
	t_element	*current;

	current = pile->first;
	while (current->next->next)
		current = current->next;
	temp = current->next;
	current->next = NULL;
	temp->next = pile->first;
	pile->first = temp;
}

void	rra(t_pile *pile_a)
{
	reverse_rotate(pile_a);
	ft_printf("rra\n");
}

void	rrb(t_pile *pile_b)
{
	reverse_rotate(pile_b);
	ft_printf("rrb\n");
}

void	rrr(t_pile *pile_a, t_pile *pile_b)
{
	reverse_rotate(pile_a);
	reverse_rotate(pile_b);
	ft_printf("rrr\n");
}
