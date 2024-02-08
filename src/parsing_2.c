/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:30:58 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/08 15:52:13 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	pb (push b) : Prend le premier élément au sommet de a et le met sur b.
	Ne fait rien si a est vide.
*/

void	push_b(t_list **stack_a, t_list	**stack_b)
{
	if(stack_a && *stack_a)
	{
		t_list	*first_a;

		first_a = *stack_a;
		*stack_a = (*stack_a)->next;
		first_a->next = NULL;
		ft_lstadd_front(stack_b, first_a); 
		ft_putstr_fd("pb\n", 1);
		return ;
	}
	else
		return ;
}

/*
	ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
	Le premier élément devient le dernier
*/

void	rotate_a(t_list **stack_a, LastNodeTracker *tracker_a)
{
	if(*stack_a && (*stack_a)->next)
	{
		t_list	*swap;

		swap = *stack_a;
		*stack_a = (*stack_a)->next;
		swap->next = NULL;
		ft_lstaddback(tracker_a, stack_a, swap);
		ft_putstr_fd("ra\n", 1);
	}
	else
		return;
}

// /*
// 	rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b.
// 	Le premier élément devient le dernier.
// */

void	rotate_b(t_list **stack_b, LastNodeTracker *tracker_b)
{
	if(*stack_b && (*stack_b)->next)
	{
		t_list	*swap;

		swap = *stack_b;
		*stack_b = (*stack_b)->next;
		swap->next = NULL;
		ft_lstaddback(tracker_b, stack_b, swap);
		ft_putstr_fd("rb\n", 1);
	}
	else
		return;
}

/*
	rr : ra et rb en même temps.
*/

void	rotate_rr(t_list **stack_a, t_list **stack_b, \
LastNodeTracker *tracker_a, LastNodeTracker *tracker_b)
{
	if((*stack_a && (*stack_a)->next) && (*stack_b && (*stack_b)->next))
	{
		t_list	*swap;

		swap = *stack_a;
		*stack_a = (*stack_a)->next;
		swap->next = NULL;
		ft_lstaddback(tracker_a, stack_a, swap);
		swap = *stack_b;
		*stack_b = (*stack_b)->next;
		swap->next = NULL;
		ft_lstaddback(tracker_b, stack_b, swap);
		ft_putstr_fd("rr\n", 1);
	}
	else
		return ;
}

/*
	rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
	la pile a. Le dernier élément devient le premier.
*/

void	reverse_rotate_a(t_list **stack_a, LastNodeTracker *tracker_a)
{
	if(!stack_a || !tracker_a)
		return ;
	t_list *front = ft_lstnew(tracker_a->lastNode->content);
	tracker_a->lastNode = tracker_a->lastNode->prev;
	ft_lstadd_front(stack_a, front);
	free(tracker_a->lastNode->next);
	tracker_a->lastNode->next = NULL;
    ft_putstr_fd("rra\n", 1);
}
