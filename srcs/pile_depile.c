/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pile_depile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:41:32 by lgoras            #+#    #+#             */
/*   Updated: 2025/02/06 14:22:23 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*initialisation(void)
{
	t_pile		*pile;

	pile = malloc(sizeof(*pile));
	if (pile == NULL)
		exit(EXIT_FAILURE);
	pile->premier = NULL;
	pile->nombre_element = 0;
	return (pile);
}

void	empiler(t_pile *pile, int nouveau_nombre)
{
	t_element	*nouveau;
	t_element	*actuel;

	actuel = pile->premier;
	nouveau = malloc(sizeof(*nouveau));
	if (pile == NULL || nouveau == NULL)
		exit(EXIT_FAILURE);
	if (pile->premier == NULL)
	{
		nouveau->nombre = nouveau_nombre;
		nouveau->suivant = pile->premier;
		pile->premier = nouveau;
		pile->nombre_element += 1;
	}
	else
	{
		while (actuel->suivant)
			actuel = actuel->suivant;
		nouveau->nombre = nouveau_nombre;
		nouveau->suivant = NULL;
		actuel->suivant = nouveau;
		pile->nombre_element += 1;
	}
}

int	depiler(t_pile *pile)
{
	int			nombre_depile;
	t_element	*element_depiler;

	if (pile == NULL)
		exit(EXIT_FAILURE);
	nombre_depile = 0;
	element_depiler = pile->premier;
	if (pile != NULL && pile->premier != NULL)
	{
		nombre_depile = element_depiler->nombre;
		pile->premier = element_depiler->suivant;
		free(element_depiler);
	}
	return (nombre_depile);
}

void	suppression(t_pile *pile)
{
	t_element	*to_delete;

	if (pile == NULL)
		exit(EXIT_FAILURE);
	while (pile->premier != NULL)
	{
		to_delete = pile->premier;
		pile->premier = pile->premier->suivant;
		free(to_delete);
	}
	free(pile);
}

void	afficher_pile(t_pile *pile)
{
	t_element	*actuel;

	if (pile == NULL)
		exit(EXIT_FAILURE);
	actuel = pile->premier;
	while (actuel != NULL)
	{
		ft_printf("| %d |\n", actuel->nombre);
		actuel = actuel->suivant;
	}
	ft_printf("NULL\n");
	ft_printf("Nombre element : %d\n", pile->nombre_element);
}
