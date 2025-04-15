/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_depile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:41:32 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/15 12:52:41 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*initialisation(void)
{
	t_pile	*pile;

	pile = malloc(sizeof(*pile));
	if (pile == NULL)
		exit(EXIT_FAILURE);
	pile->first = NULL;
	pile->nb_element = 0;
	return (pile);
}

void	empiler(t_pile *pile, int nouveau_number)
{
	t_element	*nouveau;
	t_element	*current;

	current = pile->first;
	if (pile == NULL)
		return ;
	nouveau = malloc(sizeof(*nouveau));
	if (nouveau == NULL)
		exit(EXIT_FAILURE);
	if (pile->first == NULL)
	{
		nouveau->number = nouveau_number;
		nouveau->next = pile->first;
		pile->first = nouveau;
		pile->nb_element += 1;
	}
	else
	{
		while (current->next)
			current = current->next;
		nouveau->number = nouveau_number;
		nouveau->next = NULL;
		current->next = nouveau;
		pile->nb_element += 1;
	}
}

int	depiler(t_pile *pile)
{
	int			number_depile;
	t_element	*element_depiler;

	if (pile == NULL)
		exit(EXIT_FAILURE);
	number_depile = 0;
	element_depiler = pile->first;
	if (pile != NULL && pile->first != NULL)
	{
		number_depile = element_depiler->number;
		pile->first = element_depiler->next;
		free(element_depiler);
	}
	return (number_depile);
}

void	suppression(t_pile *pile)
{
	t_element	*to_delete;

	if (pile == NULL)
		exit(EXIT_FAILURE);
	while (pile->first != NULL)
	{
		to_delete = pile->first;
		pile->first = pile->first->next;
		free(to_delete);
	}
	free(pile);
}

void	afficher_pile(t_pile *pile)
{
	t_element	*current;

	if (pile == NULL)
		exit(EXIT_FAILURE);
	current = pile->first;
	while (current != NULL)
	{
		ft_printf("| %d |\n", current->number);
		current = current->next;
	}
	ft_printf("NULL\n");
	ft_printf("Number element : %d\n", pile->nb_element);
}
