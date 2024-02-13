/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 04:05:25 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/13 15:13:06 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*last;

	last = *alst;
	if (new == NULL)
		return ;
	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	while (last->next)
	{
		last = last->next;
	}
	last->prev = last;
	last->next = new;
}
