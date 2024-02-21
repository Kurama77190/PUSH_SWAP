/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_security.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:27:43 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/18 23:39:06 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_secure_memory(char **split, t_list *stack_a);
void	ft_clear_error(char **split, t_list **stack_a);
void	ft_secure_arguments(char **argv);
void	ft_exit(void);

/* *********************************** */
/*     IMPLEMENT STACK_A_SECURITY      */
/* *********************************** */

t_list	*implemente_a(int argc, char **argv)
{
	char	**split_a;
	t_list	*stack_a;
	int		i;

	if (argc > 2)
		argv[1] = ft_strjoin(argv);
	i = 0;
	split_a = ft_split(argv[1]);
	stack_a = ft_lstnew(ft_atoi(split_a[i]));
	while (split_a[++i])
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(split_a[i])));
	if (argc > 2)
		free(argv[1]);
	ft_secure_memory(split_a, stack_a);
	free_split(split_a);
	return (stack_a);
}

/* ********************************** */
/* 		   	 MEMORY SECURITY	 	  */
/* ********************************** */

void	ft_secure_memory(char **split, t_list *stack_a)
{
	if (!ft_is_digit(split))
		ft_clear_error(split, &stack_a);
	else if (ft_is_atoi_overflow(split))
		ft_clear_error(split, &stack_a);
	else if (ft_is_double(stack_a))
		ft_clear_error(split, &stack_a);
	else if (is_sorted(stack_a))
	{
		free_split(split);
		ft_lstclear(&stack_a);
		ft_putstr_fd("is sorted !\n", 1);
		exit(EXIT_SUCCESS);
	}
	else
		return ;
}

void	ft_clear_error(char **split, t_list **stack_a)
{
	free_split(split);
	ft_lstclear(stack_a);
	ft_exit();
}

void	ft_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

/* ********************************** */
/* 		    ARGUMENTS SECURITY 	      */
/* ********************************** */

void	ft_secure_arguments(char **argv)
{
	if (ft_only_space(argv) || args_is_null(argv))
		ft_exit();
}
