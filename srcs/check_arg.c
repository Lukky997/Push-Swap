/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 13:59:22 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/23 16:15:51 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	arg_is_number(char *argv)
{
	int	index;

	index = 0;
	if (is_sign(argv[index]) && argv[index + 1] != '\0')
		index++;
	while (argv[index] && is_digit(argv[index]))
		index++;
	if (argv[index] != '\0' && !is_digit(argv[index]))
		return (0);
	return (1);
}

static int	check_double(char **argv)
{
	int		i;
	int		j;
	long	value_i;
	long	value_j;

	i = 1;
	while (argv[i])
	{
		value_i = ft_atoi(argv[i]);
		j = 1;
		while (argv[j])
		{
			if (j != i)
			{
				value_j = ft_atoi(argv[j]);
				if (value_i == value_j)
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	double_zero(char *argv)
{
	int	index;

	index = 0;
	if (is_sign(argv[index]))
		index++;
	while (argv[index] && argv[index] == '0')
		index++;
	if (argv[index] != '\0')
		return (0);
	return (1);
}

int	is_correct_input(char **argv)
{
	int	i;
	int	nb_zeros;

	nb_zeros = 0;
	i = 1;
	while (argv[i])
	{
		if (!arg_is_number(argv[i]))
			return (0);
		nb_zeros += double_zero(argv[i]);
		i++;
	}
	if (nb_zeros > 1)
		return (0);
	if (check_double(argv))
		return (0);
	return (1);
}
