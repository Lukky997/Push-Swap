/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:01:26 by lgoras            #+#    #+#             */
/*   Updated: 2025/02/06 14:30:43 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_pile *pile_a, t_pile *pile_b)
{
	t_element	*temp;

	temp = pile_b->premier;
	pile_b->premier = pile_b->premier->suivant;
	temp->suivant = pile_a->premier;
	pile_a->premier = temp;
	ft_printf("pa\n");
}

void	pb(t_pile *pile_b, t_pile *pile_a)
{
	t_element	*temp;

	temp = pile_a->premier;
	pile_a->premier = pile_a->premier->suivant;
	temp->suivant = pile_b->premier;
	pile_b->premier = temp;
	ft_printf("pb\n");
}
