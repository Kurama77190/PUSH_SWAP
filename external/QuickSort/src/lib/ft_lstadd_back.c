/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 04:05:25 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/22 13:53:42 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **alst, t_list *nw)
{
	t_list	*last;

	last = *alst;
	if (nw == NULL)
		return ;
	if (*alst == NULL)
	{
		*alst = nw;
		return ;
	}
	while (last->next)
	{
		last = last->next;
	}
	last->next = nw;
	nw->prev = last;
}
