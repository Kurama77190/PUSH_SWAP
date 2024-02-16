/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 15:53:33 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/16 16:18:05 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
	Le premier élément devient le dernier.
*/

void	rotate_a(t_list **a, bool flag)
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
	rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b.
	Le premier élément devient le dernier.
*/

void	rotate_b(t_list **b, bool flag)
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
	rr : ra et rb en même temps.
*/

void	rotate_rr(t_list **a, t_list **b)
{
	if (*a && *b)
	{
		rotate_a(a, 0);
		rotate_b(b, 0);
		print_commands("rr", 1);
	}
	else
		return ;
}
