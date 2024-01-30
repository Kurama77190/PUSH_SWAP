/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:47:31 by sben-tay          #+#    #+#             */
/*   Updated: 2024/01/30 17:05:32 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de
	la pile b. Le dernier élément devient le premier.
*/

void	reverse_rotate_b(t_list **stack_b, LastNodeTracker *tracker_b)
{
	if(!stack_b || !tracker_b)
		return ;
	t_list *front = ft_lstnew(tracker_b->lastNode->content);
	tracker_b->lastNode = tracker_b->lastNode->prev;
	ft_lstadd_front(stack_b, front);
	free(tracker_b->lastNode->next);
	tracker_b->lastNode->next = NULL;
    ft_putstr_fd("rrb\n", 1);
}

/*
	rrr : rra et rrb en même temps.
*/

void	reverse_rotate_rrr(t_list **stack_a, t_list **stack_b,\
 LastNodeTracker *tracker_a, LastNodeTracker *tracker_b)
 {
	if(!stack_a || !tracker_a || !stack_b || !tracker_b)
		return ;
	t_list *front_a = ft_lstnew(tracker_a->lastNode->content);
	tracker_a->lastNode = tracker_a->lastNode->prev;
	ft_lstadd_front(stack_a, front_a);
	free(tracker_a->lastNode->next);
	tracker_a->lastNode->next = NULL;
	t_list *front_b = ft_lstnew(tracker_b->lastNode->content);
	tracker_b->lastNode = tracker_b->lastNode->prev;
	ft_lstadd_front(stack_b, front_b);
	free(tracker_b->lastNode->next);
	tracker_b->lastNode->next = NULL;
    ft_putstr_fd("rrr\n", 1);
 }
