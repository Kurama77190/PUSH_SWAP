/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 18:16:35 by sben-tay          #+#    #+#             */
/*   Updated: 2024/03/05 16:45:27 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	target_a(t_list *a, t_list *b);
void	cost_analysis(t_list *a, t_list *b);
void	set_cheapest(t_list *a);

/* *************************** */
/* 	   INIT_NODES_A & UTILS    */
/* *************************** */

void	init_nodes_a(t_list *a, t_list *b)
{
	lst_index(a);
	lst_index(b);
	target_a(a, b);
	cost_analysis(a, b);
	set_cheapest(a);
}

/* **************************** */
/* 			HELPERS     		*/
/* **************************** */

void	target_a(t_list *a, t_list *b)
{
	t_list	*current;
	t_list	*target;
	long	best_index;

	while (a)
	{
		best_index = LONG_MIN;
		current = b;
		while (current)
		{
			if (current->content < a->content && current->content > best_index)
			{
				best_index = current->content;
				target = current;
			}
			current = current->next;
		}
		if (best_index == LONG_MIN)
			a->target_node = find_bigger(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

void	cost_analysis(t_list *a, t_list *b)
{
	int	len_a;
	int	len_b;

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}

void	set_cheapest(t_list *a)
{
	long	cheapest_value;
	t_list	*cheapest_node;

	if (!a)
		return ;
	cheapest_value = LONG_MAX;
	while (a)
	{
		if (a->push_cost < cheapest_value)
		{
			cheapest_value = a->push_cost;
			cheapest_node = a;
		}
		a = a->next;
	}
	cheapest_node->cheapest = true;
}
