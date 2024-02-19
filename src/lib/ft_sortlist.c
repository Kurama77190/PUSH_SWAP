/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 23:20:10 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/17 00:01:30 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sortlist(t_list *a)
{
	t_list	*current;
	t_list	*sort;

	current = a;
	while (current->next)
	{
		sort = a;
		while (sort->next)
		{
			if (sort->content > sort->next->content)
				ft_swap(&sort->content, &sort->next->content);
			sort = sort->next;
		}
		current = current->next;
	}
}
