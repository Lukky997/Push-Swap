/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:56:04 by lgoras            #+#    #+#             */
/*   Updated: 2025/02/06 14:31:05 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_pile *pile)
{
	t_element	*temp;
	t_element	*actuel;

	actuel = pile->premier;
	temp = pile->premier;
	pile->premier = pile->premier->suivant;
	while (actuel->suivant)
		actuel = actuel->suivant;
	temp->suivant = NULL;
	actuel->suivant = temp;
}

void	ra(t_pile *pile_a)
{
	rotate(pile_a);
	ft_printf("ra\n");
}

void	rb(t_pile *pile_b)
{
	ra(pile_b);
	ft_printf("rb\n");
}

void	rr(t_pile *pile_a, t_pile *pile_b)
{
	rotate(pile_a);
	rotate(pile_b);
	ft_printf("rr\n");
}
