/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:46:19 by sben-tay          #+#    #+#             */
/*   Updated: 2024/01/31 15:30:47 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// gcc -I../includes -E main.c

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

bool	ft_isdouble(char**	argv_1)
{
	int	i;
	int	j;

	i = 0;
	while(argv_1[i])
	{
		j = 0;
		while(argv_1[j])
		{
			if(ft_strcmp(argv_1[i], argv_1[j]) == 0)
				return false;
			j++;
		}
		i++;
	}
	return true;
}

bool	ft_secure_implement(char *argv_1)
{
	char	**stack;
	int		i;

	i = 0;
	stack = ft_split(argv_1);
	if (!ft_isdouble(stack))
		return false;
	while(stack[i])
	{
		
	}
	
	
	
}

int	main(int argc, char **argv)
{
	if (argc != 2 && !ft_secure_implement(argv[1]))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	ft_secure_implement(argv[1]);
	return 
}
