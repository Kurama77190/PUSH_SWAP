/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:34:02 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/19 18:40:52 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_for_push(t_list **stack, t_list *top_node, char stack_name);
void	rev_rotate_both(t_list **a, t_list **b, t_list *cheapest_node);
void	rotate_both(t_list **a, t_list **b, t_list *cheapest_node);
t_list	*get_cheapest(t_list *a);

/* ***************************** */
/* 		MOVE_A_TO_B & UTILS	     */
/* ***************************** */

void	move_a_to_b(t_list **a, t_list **b)
{
	t_list	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	push_b(a, b, true);
}

/* *************************** */
/* 			HELPERS     	   */
/* *************************** */

void	prep_for_push(t_list **stack, t_list *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				rotate_a(stack, true);
			else
				reverse_rotate_a(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rotate_b(stack, true);
			else
				reverse_rotate_b(stack, true);
		}
	}
}

void	rev_rotate_both(t_list **a, t_list **b, t_list *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		reverse_rotate_rrr(a, b);
	lst_index(*a);
	lst_index(*b);
}

void	rotate_both(t_list **a, t_list **b, t_list *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rotate_rr(a, b);
	lst_index(*a);
	lst_index(*b);
}

t_list	*get_cheapest(t_list *a)
{
	if (!a)
		return (NULL);
	while (a)
	{
		if (a->cheapest)
			return (a);
		a = a->next;
	}
	return (NULL);
}
