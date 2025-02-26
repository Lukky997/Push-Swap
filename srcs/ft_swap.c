/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:45:11 by lgoras            #+#    #+#             */
/*   Updated: 2025/02/04 16:12:14 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_pile *pile)
{
	t_element	*temp;
	t_element	*actuel;

	if (pile == NULL)
		return ;
	actuel = pile->premier;
	temp = actuel->suivant;
	actuel->suivant = actuel->suivant->suivant;
	temp->suivant = actuel;
	pile->premier = temp;
}

void	sa(t_pile *pile_a)
{
	ft_swap(pile_a);
	ft_printf("sa\n");
}

void	sb(t_pile *pile_b)
{
	ft_swap(pile_b);
	ft_printf("sb\n");
}

void	ss(t_pile *pile_a, t_pile *pile_b)
{
	ft_swap(pile_a);
	ft_swap(pile_b);
	ft_printf("ss\n");
}
