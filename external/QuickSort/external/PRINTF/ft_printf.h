/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.paris.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 21:30:15 by sben-tay          #+#    #+#             */
/*   Updated: 2024/01/23 21:57:49 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

// # define UINT_MAX 4294967295
// # define INT_MAX 2147483647
// # define INT_MIN -2147483648

int		ft_printf(const char *s, ...);

char	*ft_strdup(const char *s1);

void	ft_putchar(char c, int *compteur);

void	ft_putstr(char *str, int *compteur);

void	ft_putnbr(int nb, int *compteur);

void	ft_putnbr_unsigned(unsigned int nb, int *compteur);

void	ft_putnbr_base(\
		unsigned long long nbr, char *base, int *compteur, char c);

size_t	ft_strlen(const char *str);

char	*ft_strdup(const char *s1);

size_t	ft_strlcpy(char *dst, const char *src, size_t size);

int		check_arg(char c, va_list arg, int *compteur);

#endif