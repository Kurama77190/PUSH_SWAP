/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:47:31 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/17 21:23:49 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_commands(char *str, bool flag);
void	ft_swap(int *a, int *b);

/*
	sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
	Ne fait rien s’il n’y en a qu’un ou aucun.
*/

void	swap_a(t_list **a, bool flag)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (!*a || !(*a)->next)
		return ;
	first = *a;
	second = (*a)->next;
	third = second->next;
	second->next = first;
	first->next = third;
	*a = second;
	if (flag)
		print_commands("sa", flag);
	else
		return ;
}

/*
	sb (swap b) : Intervertit les 2 premiers éléments au sommet de la pile a.
	Ne fait rien s’il n’y en a qu’un ou aucun.
*/

void	swap_b(t_list **b, bool flag)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (!*b || !(*b)->next)
		return ;
	first = *b;
	second = (*b)->next;
	third = second->next;
	second->next = first;
	first->next = third;
	*b = second;
	if (flag)
		print_commands("sa", flag);
}

/*
	ss : sa et sb en même temps.
*/
void	swap_ss(t_list **a, t_list **b)
{
	swap_a(a, 0);
	swap_b(b, 0);
	print_commands("ss", 1);
}

/* *********************************** */
/* 			COMMANDS UTILS  			   */
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