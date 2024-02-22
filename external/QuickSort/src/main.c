/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:46:19 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/22 15:48:44 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_push_swap(t_list **a, t_list **b);
void	sort_five(t_list **a, t_list **b);
t_list	*find_bigger(t_list *a);
void	sort_three(t_list **a);
t_list	*find_smaller(t_list *stack);
void	push_min_lst(t_list **a, t_list **b);
int		check_pos(t_list **stack, t_list *min);
void	big_sort(t_list **a, t_list **b, int count);




/* *************************** */
/* 			MAIN PROGRAMME		*/
/* *************************** */

/*
	return 'n' size of instructions for sorting 'x' number values:

	if x 3 then n <= 3
	if x 5 then n <= 12
	if x 100 then n < 700
	if x 500 then n < 5500
*/
/*
	for 500 n = 5341;
	for 100 n = 591;
	for 5 n = 9;
	FOR 3 n = 1;

	RANDOM GENERATOR URL : https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php
*/

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || argc == (2	&& !argv[1][0]))
		return (0);
	ft_secure_arguments(argv);
	a = implemente_a(argc, argv);
	ft_print_list(a);
	ft_push_swap(&a, &b);
	ft_print_list(a);
	ft_lstclear(&a);
	ft_lstclear(&b);
}

/* *************************** */
/* 		 MAIN PUSH_SWAP 	   */
/* *************************** */

void	ft_push_swap(t_list **a, t_list **b)
{
	int		count;

	count = ft_lstsize(*a);
	if (count == 2)
		swap_a(a, true);
	else if (count == 3)
		sort_three(a);
	else if (count == 4 || count == 5)
		sort_five(a, b);
	else if (count > 5)
		big_sort(a, b, count);
}

void	sort_three(t_list **a)
{
	t_list	*bigger_node;

	bigger_node = find_bigger(*a);
	if (bigger_node == *a)
		rotate_a(a, true);
	else if ((*a)->next == bigger_node)
		reverse_rotate_a(a, true);
	if ((*a)->content > (*a)->next->content)
		swap_a(a, true);
}

void	sort_five(t_list **a, t_list **b)
{
	push_min_lst(a, b);
	sort_three(a);
	while (ft_lstsize(*b) > 0)
		push_a(a, b, true);
}

void	big_sort(t_list **a, t_list **b, int count)
{
	t_push	push;

	set_index(a);
	push.next = find_smaller(a)->index;
	push.max = find_bigger(a)->index;
	push.mid = push.max / 2 + push.next;
	push.flag = 0;
	begin_sorting(a, b, &push, count);
	while (!(check_sorting_a(a, count)))
	{
		if (ft_lstsize(*b) == 0)
			push_b(a, b, &push);
		else
			push_a(a, b, &push);
	}
}

void	begin_sorting(t_list **a, t_list **b, t_push *push, int count)
{
	int	i;

	i = -1;
	while (++i < count)
	{
		if ((*a)->index <= push->mid)
			pb(a, b);
		else
		{
			if (ft_lstsize(*b) > 1 && (((*b)->index) < (push->mid / 2)))
				rr(a, b);
			else
				ra(a);
		}
	}
	push->max = push->mid;
	push->mid = (push->max - push->next) / 2 + push->next;
	push->flag++;
}

//================================ESSAYER=========================================

void	find_next(t_list **a, t_list **b, t_push *push)
{
	if (ft_lstsize(*b) > 0 && ((*b)->index == push->next))
		pa(a, b);
	else if ((*a)->index == push->next)
	{
		(*a)->flag = -1;
		ra(a);
		push->next++;
	}
	else if ((ft_lstsize(*b)) > 2
		&& ft_lstlast(*b)->index == push->next)
		rrb(b);
	else if ((*a)->next->index == push->next)
		sa(a);
	else if ((ft_lstsize(*a)) > 1 && ((*a)->next->index == push->next)
		&& ((*b)->next->index == push->next + 1))
		ss(a, b);
	else
		return ;
	find_next(a, b, push);
}



/* *************************** */
/* 			HELPERS     	   */
/* *************************** */

t_list	*find_bigger(t_list *stack)
{
	long	max;
	t_list	*bigger;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->content > max)
		{
			max = stack->content;
			bigger = stack;
		}
		stack = stack->next;
	}
	return (bigger);
}

t_list	*find_smaller(t_list *stack)
{
	long	min;
	t_list	*smaller;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->content < min)
		{
			min = stack->content;
			smaller = stack;
		}
		stack = stack->next;
	}
	return (smaller); 
}

void	push_min_lst(t_list **a, t_list **b)
{
	while (ft_lstsize(*a) > 3)
	{
		if ((check_pos(a, find_smaller(*a))) == 0)
			push_b(a, b, true);
		else if ((check_pos(a, find_smaller(*a))) < \
		((int)ft_lstsize(*a) / 2 + 1))
			rotate_a(a, true);
		else
			reverse_rotate_a(a,true);
	}
}

int	check_pos(t_list **stack, t_list *min)
{
	t_list	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	while ((tmp != min) && tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

void	set_index(t_list **a)
{
	t_list			*tmp;
	t_list			*min_list;
	long long int	min;
	int				i;
	int				j;

	i = count_lst(a);
	j = 0;
	while (j < i)	
	{
		min = LLONG_MAX;
		tmp = *a;
		while (tmp)
		{
			if ((tmp->content < min) /*&& (tmp->index == -1)*/)
			{
				min = tmp->content;
				min_list = tmp;
			}
			tmp = tmp->next;
		}
		min_list->index = j;
		j++;
	}
}

/* *************************** */
/* 			NOTE PROJECT	   */
/* *************************** */

/*
	- PARSING SECURITY OK !
	- MEMORY MANAGEMENT OK !
	- INDEXATION OK !
	- PRE_SORT OK !
	- PUSH IN STACK B THE SMALLER THAN THE BIGGEST ELLEMENT THEN PRE_SORT ALSO BIGGEST ELEMENT THAN THE BIGGEST ELEMENT. 
	- CHOICE PIVOT KO ! -> IF THE PIVOT IS BIGGER THAN THE BIGGEST ELEMENT IN THE STACK, THE PROGRAM WILL SEGFAULT WITH RECUSIVE INFINITE LOOP
	- I DON'T KNOW IF IMPLEMENT INDEXATION IN PRE_SORT IS A GOOD IDEA...
	- QUICKSORT	IMPLEMENTING ...
	- OK, I CANNOT USE QUICKSORT AS AN ALGO BECAUSE EVEN IF IT IS VERY FAST AND LIGHTWEIGHT, IT IS WAY TOO COSTLY, WHICH IS NOT THE PURPOSE OF THIS PROJECT...
	- DELETE QUICKSORT IMPLEMENTATION...
	- GO IMPLEMENT TURKSORT ! ...
	- TURKSORT IMPLEMENTED !
	- PUSH_SWAP VALIDED, NOW GO CHECKER !
	- CHECKER VALIDED !
	- NOW GO STORE FONCTIONS.
	- STORED !
	- OK I WILL RESTART THE PROJECT BECAUSE I THINK I CAN DO BETTER THAN THAT...
	- LET'S GO QUICKSORT ROUND 2 !
*/

/* *************************** */
/* 		COMMANDS TEST ERROR		*/
/* *************************** */

/*
	echo '- check error arguments :'

	./push_swap
	./push_swap "" "9 8 7"
	./push_swap "    "
	./push_swap ""
	./push_swap 9 8 7 ""
	./push_swap "abcd"
	./push_swap "9 9 8 7 6"
	./push_swap "2147483648 2 3 4"
	./push_swap "9223372036854775808 2 3 4"

	echo ' - check valid arguments : '

	./push_swap "9 8 7
	6"
	./push_swap "  " 9 8 7 6 "  "
	./push_swap 100 1 2 3 4""5 6
*/