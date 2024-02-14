/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_security_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:24:31 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/14 13:26:06 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	ft_is_space(char c)
{
	return (c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v' || c == 32);
}

bool	ft_only_space(char *str)
{
	int	i;
	i = 0;
	while(str[i])
	{
		if(!ft_is_space(str[i]))
			return false;
		i++;
	}
	return true;
}

bool	is_sorted(t_list *stack_a)
{
	t_list	*sorted;

	sorted = stack_a;
	while(sorted->next)
	{
		if (sorted->content < sorted->next->content)
			sorted = sorted->next;
		else
			return false;
	}
	return true;
}

bool	ft_is_double(t_list *stack_a)
{
	t_list	*current;
	t_list	*checker;

	current = stack_a;
	while (current && current->next)
	{
		checker = current->next;
		while (checker)
		{
			if (current->content == checker->content)
				return true;
			checker = checker->next;
		}
		current = current->next;
	}
	return false;
}

bool	ft_is_digit(char **split)
{
	if (!split)
	return false;
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		j = 0;
		if (split[i][j] == '+' || split[i][j] == '-')
		{
			j++;
			if (split[i][j] == '\0')
				return false;
		}
		while (split[i][j])
		{
			if (split[i][j] < '0' || split[i][j] > '9')
				return false;
			j++;
		}
		i++;
	}
	return true;
}
