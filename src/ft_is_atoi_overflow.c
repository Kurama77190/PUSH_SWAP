/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_atoi_overflow.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:14:44 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/13 01:41:11 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool    ft_atoi_overflow(char *str);

bool	ft_is_atoi_overflow(char **strs)
{
	int	i;

	i = 0;
	while(strs[i])
	{
        if(ft_atoi_overflow(strs[i]))
            return true;
        i++;
    }
    return false;
}
bool	ft_atoi_overflow(char *str)
{
	size_t		len;
	long long	nb;
	int			sign;

	len = 0;
	nb = 0;
	sign = 1;

	while ((str[len] > 8 && str[len] < 14) || str[len] == 32)
		len++;
	if (str[len] == '-')
	{
		sign = -1;
		len++;
    }
	else if (str[len] == '+')
		len++;
	while (str[len] >= '0' && str[len] <= '9')
	{
		int digit = str[len] - '0';
		if (sign == 1 && (nb > INT_MAX / 10 || (nb == INT_MAX / 10 && digit > INT_MAX % 10)))
            return true; // Dépassement positif
		else if (sign == -1 && (nb > -(long long)INT_MIN / 10 || (nb == -(long long)INT_MIN / 10 && \
		digit > -(long long)INT_MIN % 10)))
			return true; // Dépassement négatif
		nb = nb * 10 + digit;
		len++;
	}
	return false; // Pas de dépassement
}
