/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:41:36 by lgoras            #+#    #+#             */
/*   Updated: 2025/02/12 13:37:27 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../ft_printf/includes/ft_printf.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_element	t_element;
struct						s_element
{
	int						nombre;
	int						index;
	int						push_cost;
	int						above_median;
	int						cheapest;
	struct s_element		*target_node;
	struct s_element		*suivant;
	struct s_element		*precedent;
};

typedef struct s_pile		t_pile;
struct						s_pile
{
	t_element				*premier;
	int						nombre_element;
};

t_pile						*initialisation(void);
void						empiler(t_pile *pile, int nouveau_nombre);
void						suppression(t_pile *pile);
void						afficher_pile(t_pile *pile);
int							depiler(t_pile *pile);
void						ft_swap(t_pile *pile);
void						sa(t_pile *pile_a);
void						sb(t_pile *pile_b);
void						ss(t_pile *pile_a, t_pile *pile_b);
void						pa(t_pile *pile_a, t_pile *pile_b);
void						pb(t_pile *pile_b, t_pile *pile_a);
void						rotate(t_pile *pile);
void						ra(t_pile *pile_a);
void						rb(t_pile *pile_b);
void						rr(t_pile *pile_a, t_pile *pile_b);
void						reverse_rotate(t_pile *pile);
void						rra(t_pile *pile_a);
void						rrb(t_pile *pile_b);
void						rrr(t_pile *pile_a, t_pile *pile_b);
char						**ft_split(char const *s, char c);

#endif