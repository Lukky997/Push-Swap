/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgoras < lgoras@student.42.fr >            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:00:34 by lgoras            #+#    #+#             */
/*   Updated: 2024/11/26 16:13:48 by lgoras           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
void	ft_putchar(char c, int *i);
void	ft_putstr(char *str, int *i);
void	ft_print_adress(unsigned long long ptr, int *i);
void	ft_putnbr(int n, int *i);
void	ft_putnbr_unsigned(unsigned int n, int *i);
void	ft_putnbr_base(unsigned int nbr, char *base, int *i);

#endif