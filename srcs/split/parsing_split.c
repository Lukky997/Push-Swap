/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 14:04:50 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/23 16:15:41 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	number_split(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]) && argv[i + 1] != '\0')
		i++;
	while (argv[i] && is_digit(argv[i]))
		i++;
	if (argv[i] != '\0' && !is_digit(argv[i]))
		return (0);
	return (1);
}

static int	double_split(char **argv)
{
	int		i;
	int		j;
	long	value_i;
	long	value_j;

	i = 0;
	while (argv[i])
	{
		value_i = ft_atoi(argv[i]);
		j = i + 1;
		while (argv[j])
		{
			value_j = ft_atoi(argv[j]);
			if (value_i == value_j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int	zero_split(char *argv)
{
	int	i;

	i = 0;
	if (is_sign(argv[i]))
		i++;
	while (argv[i] && argv[i] == '0')
		i++;
	if (argv[i] != '\0')
		return (0);
	return (1);
}

int	good_split(char **argv)
{
	int	i;
	int	nb_zeros;

	nb_zeros = 0;
	i = 0;
	while (argv[i])
	{
		if (!number_split(argv[i]))
			return (0);
		nb_zeros += zero_split(argv[i]);
		i++;
	}
	if (nb_zeros > 1)
		return (0);
	if (double_split(argv))
		return (0);
	return (1);
}
