/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_reverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:13:36 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/17 16:56:52 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
	la pile a. Le dernier élément devient le premier.
*/

void	reverse_rotate_a(t_list **a, bool flag)
{
	t_list	*last;
	t_list	*second_last;

	if (*a && (*a)->next)
	{
		last = *a;
		second_last = NULL;
		while (last->next != NULL)
		{
			second_last = last;
			last = last->next;
		}
		if (second_last)
			second_last->next = NULL;
		ft_lstadd_front(a, last);
		print_commands("rra", flag);
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
	t_list	*last;
	t_list	*second_last;

	if (*b && (*b)->next)
	{
		last = *b;
		second_last = NULL;
		while (last->next != NULL)
		{
			second_last = last;
			last = last->next;
		}
		if (second_last)
			second_last->next = NULL;
		ft_lstadd_front(b, last);
		print_commands("rrb", flag);
	}
	else
		return ;
}

/*
	rrr : rra et rrb en même temps.
*/

void	reverse_rotate_rrr(t_list **a, t_list **b)
{
	if (*a && (*a)->next && *b && (*b)->next)
	{
		reverse_rotate_a(a, 0);
		reverse_rotate_a(b, 0);
		print_commands("rrr", 1);
	}
	else
		return ;
}
