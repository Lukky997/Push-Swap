/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 13:50:17 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/19 12:42:11 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
