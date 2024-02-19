/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 13:52:43 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/19 01:07:00 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//FONCTION OK !
void	lst_index(t_list *a)
{
	int		i;
	int		median;

	i = 0;
	if (!a)
		return ;
	median = ft_lstsize(a) / 2;
	while (a)
	{
		a->index = i;
		if (i <= median)
			a->above_median = true;
		else
			a->above_median = false;
		a = a->next;
		i++;
	}
}
