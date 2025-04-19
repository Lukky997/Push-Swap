/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 16:01:26 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/19 15:10:13 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_pile *pile_a, t_pile *pile_b)
{
	t_element	*temp;

	if (!pile_b || !pile_b->first)
		return ;
	temp = pile_b->first;
	pile_b->first = pile_b->first->next;
	temp->next = pile_a->first;
	pile_a->first = temp;
	pile_a->nb_element++;
	pile_b->nb_element--;
	ft_printf("pa\n");
}

void	pb(t_pile *pile_b, t_pile *pile_a)
{
	t_element	*temp;

	if (!pile_a || !pile_a->first)
		return ;
	temp = pile_a->first;
	pile_a->first = pile_a->first->next;
	temp->next = pile_b->first;
	pile_b->first = temp;
	pile_b->nb_element++;
	pile_a->nb_element--;
	ft_printf("pb\n");
}

