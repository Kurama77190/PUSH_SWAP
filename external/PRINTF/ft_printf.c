/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 14:15:34 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/16 01:56:44 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_arg(char c, va_list arg, int *compteur)
{
	if (c == 'c')
		ft_putchar((char)va_arg(arg, int), compteur);
	else if (c == '%')
		ft_putchar('%', compteur);
	else if (c == 's')
		ft_putstr(va_arg(arg, char *), compteur);
	else if (c == 'd' || c == 'i')
		ft_putnbr((int)va_arg(arg, int), compteur);
	else if (c == 'u')
		ft_putnbr_unsigned(va_arg(arg, unsigned int), compteur);
	else if (c == 'x')
		ft_putnbr_base((unsigned int)va_arg(arg, unsigned int), \
		"0123456789abcdef", compteur, c);
	else if (c == 'X')
		ft_putnbr_base((unsigned int)va_arg(arg, unsigned int), \
		"0123456789ABCDEF", compteur, c);
	else if (c == 'p')
		ft_putnbr_base((unsigned long long)va_arg(arg, unsigned long long), \
		"0123456789abcdef", compteur, c);
	else
		return (-1);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	size_t		i;
	va_list		arg;
	char		*str;
	int			compteur;

	if (!s)
		return (-1);
	i = 0;
	compteur = 0;
	str = ft_strdup(s);
	va_start(arg, s);
	while (str[i])
	{
		if (str[i] == '%')
		{
			check_arg(str[i + 1], arg, &compteur);
			i++;
		}
		else
			ft_putchar(str[i], &compteur);
		i++;
	}
	va_end(arg);
	free(str);
	return (compteur);
}
