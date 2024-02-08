/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:46:19 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/08 18:58:28 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"



// bool	ft_secure(t_list *stack_a)
// {
// 	if(ft_is_double(stack_a))
// 		return false;
// 	if(!ft_is_digit(stack_a))
// 		return false;
// 	if(!ft_is_int(stack_a))
// 		return false;
// 	else
// 		return true;
// }

bool	ft_is_double(t_list *stack_a)
{
	if (!stack_a)
		return false;

	t_list	*index;
	t_list 	*checker;
	
	index = stack_a;
	while(index)
	{
		checker = stack_a;
		while(checker)
		{
			if(index->content == checker->content && index != checker)
				return true;
			checker = checker->next;
		}
		index = index->next;
	}
	return false;
}

bool	ft_is_digit(t_list *stack_a);

bool	ft_is_int(t_list *stack_a)
{
	if (!stack_a)
		return false;
	
	t_list	*check;

	check = stack_a;
	while(check)
	{
		if (!(check->content >= INT_MIN && check->content <= INT_MAX))
			return false;
		check = check->next;
	}
	return true;
}
void	implemente_stack(t_list *stack_a, char **argv)
{
	char **split_stack = ft_split(argv[1], ' ');
	LastNodeTracker	*tracker_a;
	int i = 0;
	
	tracker_a = malloc(sizeof(t_list));
	if(!tracker_a)
	{
		free(split_stack);	
		return NULL;
	}
	stack_a = ft_lstnew(ft_atoi(split_stack[i++]));
	tracker_a->lastNode = stack_a;
	while(split_stack[i])
	{
		ft_lstaddback(tracker_a, &stack_a, ft_lstnew(ft_atoi(split_stack[i])));
		i++;
	}
	return (stack_a);	
}
t_list	*ft_secure_stack(int argc, char **argv)
{
	(void) argc;
	t_list	*stack_a;
	implemente_stack(stack_a);
	// ft_is_digit(split_stack);

	if (ft_is_double(stack_a))
	{
		ft_lstclear(&stack_a, free);	
		ft_exit();
	}
	return stack_a;
}



int main(int argc, char **argv)
{
	(void)argc;
	t_list	*stack_a;
	stack_a = ft_secure_stack(argc, argv);
	ft_print_list(stack_a);
	ft_printf("la valeur de retour de ft_is_double est : %d\n", ft_is_double(stack_a));
	ft_printf("la valeur de retour de ft_is_int : %d\n", ft_is_int(stack_a));
}
