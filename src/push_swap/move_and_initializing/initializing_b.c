/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:20:42 by sben-tay          #+#    #+#             */
/*   Updated: 2024/03/05 16:43:35 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_b(t_list *a, t_list *b);
void	move_b_to_a(t_list **a, t_list **b);

/* *************************** */
/* 	   INIT_NODES_B & UTILS    */
/* *************************** */

void	init_nodes_b(t_list *a, t_list *b)
{
	lst_index(a);
	lst_index(b);
	target_b(a, b);
}

/* *************************** */
/* 			HELPERS     	   */
/* *************************** */

void	target_b(t_list *a, t_list *b)
{
	t_list	*current;
	t_list	*target;
	long	best_index;

	while (b)
	{
		best_index = LONG_MAX;
		current = a;
		while (current)
		{
			if (current->content > b->content && current->content < best_index)
			{
				best_index = current->content;
				target = current;
			}
			current = current->next;
		}
		if (best_index == LONG_MAX)
			b->target_node = find_smaller(a);
		else
			b->target_node = target;
		b = b->next;
	}
}
