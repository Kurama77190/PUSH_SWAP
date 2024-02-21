/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 00:00:51 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/17 00:01:07 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstcopy(t_list *lst)
{
	t_list	*copy_lst;

	if (lst == NULL)
		return (NULL);
	copy_lst = NULL;
	while (lst != NULL)
	{
		ft_lstadd_back(&copy_lst, ft_lstnew(lst->content));
		lst = lst->next;
	}
	return (copy_lst);
}
