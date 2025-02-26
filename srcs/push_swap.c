/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:09:16 by lgoras            #+#    #+#             */
/*   Updated: 2025/02/26 17:58:00 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int pile_sorted(t_pile *pile)
{
    t_element *current_a;

    current_a = pile->first;
    while(current_a->next != NULL)
    {
        if (current_a->number > current_a->next->number)
            return (0);
        current_a = current_a->next;
    }
    return (1);
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