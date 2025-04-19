/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 14:24:23 by lgoras            #+#    #+#             */
/*   Updated: 2025/04/19 12:41:18 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(char *str)
{
	int	sign;
	int	result;

	sign = 1;
	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '-' || *str == '+')
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

static size_t	count_words(char const *s, char c)
{
	size_t	compteur;
	size_t	index;

	compteur = 0;
	index = 0;
	while (s[index])
	{
		if (s[index] != c && (s[index + 1] == c || s[index + 1] == '\0'))
			compteur++;
		index++;
	}
	return (compteur);
}

static size_t	len_str(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s != c && *s++)
		i++;
	return (i);
}

char	**free_split(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	word_index;
	size_t	letter_index;

	word_index = 0;
	tab = malloc(sizeof(char *) * (count_words((char *)s, c) + 1));
	if (!tab)
		return (NULL);
	while (*s && *s == c)
		s++;
	while (*s)
	{
		letter_index = 0;
		tab[word_index] = malloc(sizeof(char) * (len_str(s, c) + 1));
		if (!tab[word_index])
			return (free_split(tab));
		while (*s && *s != c)
			tab[word_index][letter_index++] = *s++;
		while (*s && *s == c)
			s++;
		tab[word_index][letter_index] = '\0';
		word_index++;
	}
	tab[word_index] = NULL;
	return (tab);
}
