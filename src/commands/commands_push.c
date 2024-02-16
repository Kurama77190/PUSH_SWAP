/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:30:58 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/16 16:48:50 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	pa (push a) : Prend le premier élément au sommet de b et le met sur a.
	Ne fait rien si b est vide.
*/

void	push_a(t_list **a, t_list **b, bool flag)
{
	if (b && *b)
	{
		t_list	*first_b;

		first_b = *b;
		*b = (*b)->next;
		first_b->next = NULL;
		ft_lstadd_front(a, first_b); 
		print_commands("pa", flag);
	}
	else
		return ;
}

/*
	pb (push b) : Prend le premier élément au sommet de a et le met sur b.
	Ne fait rien si a est vide.
*/

void	push_b(t_list **a, t_list **b, bool flag)
{
	if (a && *a)
	{
		t_list	*first_a;

		first_a = *a;
		*a = (*a)->next;
		first_a->next = NULL;
		ft_lstadd_front(b, first_a); 
		print_commands("pb", flag);
	}
	else
		return ;
}
