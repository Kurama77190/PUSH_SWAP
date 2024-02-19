/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 16:58:52 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/19 01:04:17 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// FONCTION OK !
void	Three_sort(t_list **a)
{
	t_list	*bigger_node;

	bigger_node = find_bigger(*a);
	if (bigger_node == *a)
		rotate_a(a, true);
	else if ((*a)->next == bigger_node)
		reverse_rotate_a(a, true);
	if ((*a)->content > (*a)->next->content)
		swap_a(a, true);
}

t_list	*find_bigger(t_list *a)
{
	long	max;
	t_list	*bigger;

	if (!a)
		return (NULL);
	max = LONG_MIN;
	while (a)
	{
		if (a->content > max)
		{
			max = a->content;
			bigger = a;

		}
		a = a->next;
	}
	return (bigger);
}

t_list	*find_smaller(t_list *a)
{
	long	min;
	t_list	*smaller;

	if (!a)
		return (NULL);
	min = LONG_MAX;
	while (a)
	{
		if (a->content < min)
		{
			min = a->content;
			smaller = a;
		}
		a = a->next;
	}
	return (smaller); 
}
