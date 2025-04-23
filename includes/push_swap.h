/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:41:36 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/23 15:27:16 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../ft_printf/includes/ft_printf.h"
# include <limits.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

t_stack				*initialisation(int argc, char **argv);
void				get_index(t_stack *stack_a, int stack_size);

int					stack_sorted(t_stack *stack);
void				sort_three(t_stack **stack);
void				sort(t_stack **stack_a, t_stack **stack_b);

int					get_lowest_index_position(t_stack **stack);
void				get_target_position(t_stack **stack_a, t_stack **stack_b);

void				get_cost(t_stack **stack_a, t_stack **stack_b);
void				do_cheapest_move(t_stack **stack_a, t_stack **stack_b);
void				do_move(t_stack **stack_a, t_stack **stack_b, int cost_a,
						int cost_b);

void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);

t_stack				*get_stack_bottom(t_stack *stack);
t_stack				*get_stack_before_bottom(t_stack *stack);
t_stack				*stack_new(int value);
void				stack_add_bottom(t_stack **stack, t_stack *new);
int					stack_len(t_stack *stack);

long int			ft_atoi(const char *str);
int					nb_abs(int nb);
void				free_stack(t_stack **stack);
void				send_error(t_stack **stack_a, t_stack **stack_b);

int					is_correct_input(char **argv);
int					is_digit(char c);
int					is_sign(char c);
int					nbstr_cmp(const char *s1, const char *s2);

char				**ft_split(char const *s, char c);
int					ft_strlen(const char *str);
int					good_split(char **av);
t_stack				*split_init(char **av);
char				**free_if_error(char **split);

void				call_function(t_stack *stack_a, t_stack *stack_b,
						int stack_size);
void				push_swap(t_stack **stack_a, t_stack **stack_b,
						int stack_size);
void				send_error_split(char **result);

#endif