/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 13:48:12 by lgoras            #+#    #+#             */
/*   Updated: 2025/02/13 13:44:21 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"
static long ft_atoi(const char *str)
{
    int	sign;
	long	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		result *= 10;
		result += *str - '0';
		str++;
	}
	return (result * sign);
}

static void append_note(t_pile **stack, int n)
{
    t_element *node;
    t_element *last_node;

    if (!stack)
        return ;
    node = malloc(sizeof(t_element));
    if (!node)
        return ;
    node->suivant = NULL;
    node->nombre = n;
    if(!(*stack))
    {
        *stack = node;
        node->precedent = NULL;
    }
    else
    {
        last_node = find_last(*stack);
        last_node->suivant = node;
        node->precedent = last_node;
    }
}

void    init_stack_a(t_pile **pile_a, char **argv)
{
    long nbr;
    int index;

    index = 0;
    while(argv[index])
    {
        if (error_syntax(argv[index]))
            free_errors(pile_a);
        nbr = ft_atoi(argv[index]);
        if (nbr < INT_MIN || nbr > INT_MAX)
            free_errors(pile_a);
        if (errors_dupplicate(*pile_a, (int)nbr))
            free_errors(pile_a);
        append_node(pile_a, (int)nbr);
        index++;
    }
}