/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:45:02 by lgoras            #+#    #+#             */
/*   Updated: 2025/02/13 13:49:54 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool stack_sorted(t_element *stack)
{
    if (!stack)
        return(1);
    while(stack->suivant)
    {
        if (stack->nombre > stack->suivant->nombre)
            return (false);
        stack = stack->suivant;
    }
    return(true);
}

t_pile *find_min(t_element * stack)
{
    long min;
    t_element *min_node;

    if (!stack)
        return (NULL);
    min = LONG_MAX;
    while(stack)
    {
        if(stack->nombre < min)
        {
            min = stack->nombre;
            min_node = stack;
        }
        stack = stack->suivant;
    }
    return (min_node);
}