/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_security_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:24:31 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/18 23:25:26 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* *********************************** */
/* 			  UTILS SECURITY	   	   */
/* *********************************** */

bool	is_sorted(t_list *stack_a)
{
	t_list	*sorted;

	sorted = stack_a;
	while (sorted->next)
	{
		if (sorted->content > sorted->next->content)
			return (false);
		sorted = sorted->next;
	}
	return (true);
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
				return (true);
			checker = checker->next;
		}
		current = current->next;
	}
	return (false);
}

bool	ft_is_digit(char **split)
{
	int	i;
	int	j;

	if (!split)
		return (false);
	i = 0;
	while (split[i])
	{
		j = 0;
		if (split[i][j] == '+' || split[i][j] == '-')
		{
			j++;
			if (split[i][j] == '\0')
				return (false);
		}
		while (split[i][j])
		{
			if (split[i][j] < '0' || split[i][j] > '9')
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	ft_only_space(char **strs)
{
	int	i;
	int	j;

	i = 1;
	while (strs[i])
	{
		j = 0;
		while (strs[i][j])
		{
			if (!ft_is_space(strs[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	args_is_null(char **strs)
{
	int	i;

	i = 1;
	if (!strs[i][0])
		return (true);
	while (strs[i])
	{
		if (!strs[i][0])
			return (true);
		i++;
	}
	return (false);
}
