/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:49:50 by lgoras            #+#    #+#             */
/*   Updated: 2025/02/06 14:30:24 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_pile *pile)
{
	t_element	*temp;
	t_element	*actuel;

	actuel = pile->premier;
	while (actuel->suivant->suivant)
		actuel = actuel->suivant;
	temp = actuel->suivant;
	actuel->suivant = NULL;
	temp->suivant = pile->premier;
	pile->premier = temp;
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
