/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:50:17 by lgoras            #+#    #+#             */
/*   Updated: 2025/02/13 13:53:25 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_element **pile_a)
{
    t_element * biggest_node;

    biggest_node = find_max(*pile_a);
    if (biggest_node == *pile_a)
        ra(pile_a);
    else if ((*pile_a)->suivant == biggest_node)
        rra(pile_a);
    if ((*pile_a)->nombre > (*pile_a)->suivant->nombre)
        sa(pile_a);
}