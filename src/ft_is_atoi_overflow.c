/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_atoi_overflow.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 20:14:44 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/12 20:28:26 by sben-tay         ###   ########.fr       */
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
bool    ft_atoi_overflow(char *str)
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
		sign *= -1;
		len++;
	}
	else if (str[len] == '+')
		len++;
	while (str[len] >= '0' && str[len] <= '9')
	{
		nb = nb * 10 + (str[len] - '0');
		len++;
	}
	if(nb * sign >= INT_MIN && nb * sign <= INT_MAX)
		return false;
	return true;
}
