/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:46:19 by sben-tay          #+#    #+#             */
/*   Updated: 2024/01/29 18:59:35 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// gcc -I../includes -E main.c

int	main(void)
{
	int	*a = malloc(sizeof(int));
	int *b = malloc(sizeof(int));
	int *c = malloc(sizeof(int));
	
	int *d = malloc(sizeof(int));
	int *e = malloc(sizeof(int));
	int *f = malloc(sizeof(int));

	LastNodeTracker *tracker_a = malloc(sizeof(t_list));
	LastNodeTracker	*tracker_b = malloc(sizeof(t_list));
	
	*a = 10;
	*b = 20;
	*c = 30;

	*d = 40;
	*e = 50;
	*f = 60;
	


	
	t_list	*stack_a = ft_lstnew(&a);
	tracker_a->lastNode = stack_a;
	ft_lstaddback(tracker_a, &stack_a, ft_lstnew(b));
	ft_lstaddback(tracker_a, &stack_a, ft_lstnew(c));

	t_list	*stack_b = ft_lstnew(d);
	tracker_b->lastNode = stack_b;
	ft_lstaddback(tracker_b, &stack_b, ft_lstnew(e));
	ft_lstaddback(tracker_b, &stack_b, ft_lstnew(f));

	ft_printf("liste stack_a : \n");
	ft_print_list(stack_a);
}

// printf("----------------------------\n");
// 	reverse_rotate_a(&stack_a);
// 	print_lst(stack_a);
// }
// retester la fonction swap_ss;