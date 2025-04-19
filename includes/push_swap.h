/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:41:36 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/19 13:12:57 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../ft_printf/includes/ft_printf.h"
# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_element
{
	int					index;
	int					number;
	int					push_cost;
	int					above_median;
	struct s_element	*target_node;
	struct s_element	*next;
}						t_element;

typedef struct s_pile
{
	t_element			*first;
	struct s_element	*smallest;
	struct s_element	*biggest;
	int					nb_element;
}						t_pile;

t_pile					*initialisation(void);
void					empiler(t_pile *pile, int nouveau_number);
void					suppression(t_pile *pile);
void					afficher_pile(t_pile *pile);
int						depiler(t_pile *pile);
void					ft_swap(t_pile *pile);
void					sa(t_pile *pile_a);
void					sb(t_pile *pile_b);
void					ss(t_pile *pile_a, t_pile *pile_b);
void					pa(t_pile *pile_a, t_pile *pile_b);
void					pb(t_pile *pile_b, t_pile *pile_a);
void					rotate(t_pile *pile);
void					ra(t_pile *pile_a);
void					rb(t_pile *pile_b);
void					rr(t_pile *pile_a, t_pile *pile_b);
void					reverse_rotate(t_pile *pile);
void					rra(t_pile *pile_a);
void					rrb(t_pile *pile_b);
void					rrr(t_pile *pile_a, t_pile *pile_b);
char					**ft_split(char const *s, char c);
char					**free_split(char **s);
int						main(int argc, char **argv);
int						pile_sorted(t_pile *pile);
void					fill_a(t_pile *pile_a, char **argv);
void					push_swap(t_pile *pile_a, t_pile *pile_b);
void					sort_three(t_pile *pile_a);
void					find_smallest_and_biggest(t_pile *pile_a,
							t_pile *pile_b);
void					find_target(t_pile *pile_a, t_pile *pile_b);
int						ft_atoi(char *str);
void					set_index(t_pile *pile);
void					set_above_median(t_pile *pile);
void					calculate_cost(t_pile *pile_a, t_pile *pile_b);
t_element				*find_cheapest(t_pile *pile);
void					do_move(t_pile *pile_a, t_pile *pile_b,
							t_element *cheapest, int direction);
void					do_cheapest_move(t_pile *pile_a, t_pile *pile_b,
							int direction);
void					finish_sort(t_pile *pile_a, t_pile *pile_b);
void					rotate_to_min_top(t_pile *pile_a);

#endif