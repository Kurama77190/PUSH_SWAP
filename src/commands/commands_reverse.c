/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_reverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:13:36 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/16 17:52:04 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
	la pile a. Le dernier élément devient le premier.
*/

void	reverse_rotate_a(t_list **a, bool flag)
{
	t_list	*current;
	t_list	*delete;

	if (*a && a)
	{
		current = ft_lstlast(*a);
		delete = current;
		ft_lstadd_front(a, current);
		delete->prev->next = NULL;
		print_commands("ra", flag);
	}
	else
		return ;
}

/*
	rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de
	la pile b. Le dernier élément devient le premier.
*/

void	reverse_rotate_b(t_list **b, bool flag)
{
	t_list	*current;
	t_list	*delete;

	if (*b && b)
	{
		current = ft_lstlast(*b);
		delete = current;
		ft_lstadd_front(b, current);
		delete->prev->next = NULL;
		print_commands("rb", flag);
	}
	else
		return ;
}

/*
	rrr : rra et rrb en même temps.
*/

void	reverse_rotate_rrr(t_list **a, t_list **b)
{
	if (*a && *b)
	{
		reverse_rotate_a(a, 0);
		reverse_rotate_a(b, 0);
		print_commands("rrr", 1);
	}
	else
		return ;
}
