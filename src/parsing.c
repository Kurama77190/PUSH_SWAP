/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:13:36 by sben-tay          #+#    #+#             */
/*   Updated: 2024/01/29 18:20:55 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/*
	sa (swap a) : Intervertit les 2 premiers éléments au sommet de la pile a.
	Ne fait rien s’il n’y en a qu’un ou aucun.
*/

void	swap_a(t_list *stack_a)
{
	if (stack_a && stack_a->next)
	{
		ft_swap((int *)(stack_a->content), (int *)(stack_a->next->content));
		ft_putstr_fd("sa\n", 1);
		return ;
	}
	else
		return ;
}

/*
	sb (swap b ) : Intervertit les 2 premiers éléments au sommet de la pile b.
	Ne fait rien s’il n’y en a qu’un ou aucun.
*/

void	swap_b(t_list *stack_b)
{
	if (stack_b && stack_b->next)
	{
		ft_swap((int *)(stack_b->content), (int *)(stack_b->next->content));
		ft_putstr_fd("sb\n", 1);
		return ;
	}
	else
		return ;
}

/*
	ss : sa et sb en même temps.
*/

void	swap_ss(t_list	*stack_a, t_list *stack_b)
{
	if((stack_a && stack_a->next) && (stack_b && stack_b->next))
	{
		ft_swap((int *)(stack_a->content), (int *)(stack_a->next->content));
		ft_swap((int *)(stack_b->content), (int *)(stack_b->next->content));
		ft_putstr_fd("ss\n", 1);
	}
	else
		return ;
}

/*
	pa (push a) : Prend le premier élément au sommet de b et le met sur a.
	Ne fait rien si b est vide.
*/

void	push_a(t_list **stack_a, t_list	**stack_b)
{
	if(stack_b && *stack_b)
	{
		t_list	*first_b;

		first_b = *stack_b;
		*stack_b = (*stack_b)->next;
		first_b->next = NULL;
		ft_lstadd_front(stack_a, first_b); 
		ft_putstr_fd("pa\n", 1);
		return ;
	}
	else
		return ;
}