/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 04:05:25 by sben-tay          #+#    #+#             */
/*   Updated: 2024/01/31 17:13:52 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstaddback(LastNodeTracker *tracker, t_list **alst, t_list *new)
{
	if (new == NULL)
		return ;
	if (*alst == NULL)
	{
		*alst = new;
		tracker->lastNode = new;
		return ;
	}
	new->prev = tracker->lastNode;
	tracker->lastNode->next = new;
	//tracker
	tracker->lastNode = new;
}
