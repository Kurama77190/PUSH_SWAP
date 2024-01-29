/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:30:58 by sben-tay          #+#    #+#             */
/*   Updated: 2024/01/29 18:43:43 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include "../external/PRINTF/ft_printf.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

//structure qui point sur le dernier ellement de ma liste.
typedef struct	LastNodeTracker
{
	t_list		*lastNode;
}				LastNodeTracker;

void	ft_putstr_fd(char *s, int fd);

void	push_b(t_list **stack_a, t_list	**stack_b);

void	ft_swap(int *a, int *b);

void	swap_a(t_list *stack_a);

void	swap_b(t_list *stack_b);

void	swap_ss(t_list	*stack_a, t_list *stack_b);

void	push_a(t_list **stack_a, t_list	**stack_b);

void	ft_swap(int *a, int *b);

void	ft_lstaddback(LastNodeTracker *tracker, t_list **alst, t_list *new);

void	ft_print_list(t_list *test);

void	ft_lstadd_front(t_list **lst, t_list *new);

void	ft_lstdelone(t_list *lst, void (*del)(void*));

t_list	*ft_lstnew(void *content);

#endif
