/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:47:31 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/16 15:23:45 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_commands(char *str, bool flag);
void	ft_swap(int *a, int *b);

/*
	sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
	Ne fait rien s’il n’y en a qu’un ou aucun.
*/

void	swap_a(t_list *a, bool flag)
{
	t_list	*current;

	current = a;
	if (current && current->next)
	{
		ft_swap(&current->content, &current->next->content);
		print_commands("sa", flag);
	}
	else
		return ;
}

/*
	sb (swap b) : Intervertit les 2 premiers éléments au sommet de la pile a.
	Ne fait rien s’il n’y en a qu’un ou aucun.
*/

void	swap_b(t_list *b, bool flag)
{
	t_list	*current;

	current = b;
	if (current && current->next)
	{
		ft_swap(&current->content, &current->next->content);
		print_commands("sb", flag);
	}
	else
		return ;
}

/*
	ss : sa et sb en même temps.
*/
void	swap_ss(t_list *a, t_list *b)
{
	swap_a(a, 0);
	swap_b(b, 0);
	print_commands("ss", 1);
}

/* *********************************** */
/* 			COMMANDS UTILS  	   	   */
/* *********************************** */

void	print_commands(char *str, bool flag)
{
	if (flag)
	{
		ft_putstr_fd(str, 1);
		ft_putstr_fd("\n", 1);
	}
}

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}