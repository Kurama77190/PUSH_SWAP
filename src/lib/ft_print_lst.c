/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 18:03:08 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/16 02:04:54 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_list(t_list *test)
{
	t_list	*print;

	print = test;
	while (print)
	{
		printf("%d ", print->content);
		print = print->next;
	}
	printf("NULL\n");
}
