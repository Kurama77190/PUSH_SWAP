/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:46:19 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/19 01:41:38 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_swap(t_list **a, t_list **b);
void	init_nodes_a(t_list *a, t_list *b);
static void	target_a(t_list *a, t_list *b);
static void	cost_analysis(t_list *a, t_list *b);
void	set_cheapest(t_list *a);
void	init_nodes_b(t_list *a, t_list *b);
static void	target_b(t_list *a, t_list *b);
static void	move_a_to_b(t_list **a, t_list **b);
static void	move_b_to_a(t_list **a, t_list **b);
void	prep_for_push(t_list **stack, t_list *top_node, char stack_name);
static void	rev_rotate_both(t_list **a, t_list **b, t_list *cheapest_node);
static void	rotate_both(t_list **a, t_list **b, t_list *cheapest_node);
t_list	*get_cheapest(t_list *a);
static void	min_on_top(t_list **a);



/* *************************** */
/* 			MAIN PROGRAMME		*/
/* *************************** */

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
	if (!is_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			swap_a(&a, 1);
		else if (ft_lstsize(a) == 3)
			Three_sort(&a);
		else
			ft_push_swap(&a, &b);
	}
	ft_lstclear(&a);
	ft_lstclear(&b);
}

/* *************************** */
/* 			HELPERS     		*/
/* *************************** */


// FONCTION OK !
void	ft_push_swap(t_list **a, t_list **b)
{	
	int	len_a;

	len_a = ft_lstsize(*a);
	if (len_a-- > 3 && !is_sorted(*a))
		push_b(a, b, true);
	if (len_a-- > 3 && !is_sorted(*a))
		push_b(a, b, true);
	while (len_a-- > 3 && !is_sorted(*a))
	{
		init_nodes_a(*a, *b);
		move_a_to_b(a, b);
	}
	Three_sort(a);
	while (*b)
	{
		init_nodes_b(*a, *b);
		move_b_to_a(a, b);
	}
	lst_index(*a);
	min_on_top(a);
}
// FONCTION OK !
static void	min_on_top(t_list **a)
{
	while((*a)->content != find_smaller(*a)->content)
	{
		if (find_smaller(*a)->above_median)
			rotate_a(a, true);
		else
			reverse_rotate_a(a, true);
	}	
}

/* *************************** */
/* 	  INIT_NODES_B & UTILS	   */
/* *************************** */
// FONCTION OK !
void	init_nodes_b(t_list *a, t_list *b)
{
	lst_index(a);
	lst_index(b);
	target_b(a, b);
}

// FONCTION OK !
static void	target_b(t_list *a, t_list *b)
{
	t_list	*current;
	t_list	*target;
	long 	best_index;

	while (b)
	{
		best_index = LONG_MAX;
		current = a;
		while (current)
		{
			if (current->content > b->content \
			&& current->content < best_index)
			{
				best_index = current->content;
				target = current;
			}
			current = current->next;
		}
		if (best_index == LONG_MAX)
			b->target_node = find_smaller(a);
		else
			b->target_node = target;
		b = b->next;
	}
}
//FONCTION OK !
static void	move_b_to_a(t_list **a, t_list **b)
{
	prep_for_push(a, (*b)->target_node, 'a');
	push_a(a, b, true);
}

/*(***************************** */
/* 	  MOVE TO (A & B) & UTILS	 */
/* ***************************** */
//FONCTION OK !
static void	move_a_to_b(t_list **a, t_list **b)
{
	t_list	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (cheapest_node->above_median && cheapest_node->target_node->above_median)
		rotate_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median) \
		&& !(cheapest_node->target_node->above_median))
		rev_rotate_both(a, b, cheapest_node);
	prep_for_push(a, cheapest_node, 'a');
	prep_for_push(b, cheapest_node->target_node, 'b');
	push_b(a, b, true);
}

void	prep_for_push(t_list **stack, t_list *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				rotate_a(stack, true);
			else
				reverse_rotate_a(stack, true);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rotate_b(stack, true);
			else
				reverse_rotate_b(stack, true);
		}
	}
}
// FONCTION OK !
static void	rev_rotate_both(t_list **a, t_list **b, t_list *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		reverse_rotate_rrr(a, b);
	lst_index(*a);
	lst_index(*b);
}
// FONCTION OK !
static void	rotate_both(t_list **a, t_list **b, t_list *cheapest_node)
{
	while (*b != cheapest_node->target_node && *a != cheapest_node)
		rotate_rr(a, b);
	lst_index(*a);
	lst_index(*b);
}

t_list	*get_cheapest(t_list *a)
{
	if (!a)
		return (NULL);
	while (a)
	{
		if (a->cheapest)
			return (a);
		a = a->next;
	}
	return (NULL);
}

/* *************************** */
/* 	  INIT_NODES_A & UTILS	   */
/* *************************** */
// FONCTION OK !
void	init_nodes_a(t_list *a, t_list *b)
{
	lst_index(a);
	lst_index(b);
	target_a(a, b);
	cost_analysis(a, b);
	set_cheapest(a);
}
// FONCTION OK !
static void	target_a(t_list *a, t_list *b)
{
	t_list	*current;
	t_list	*target;
	long 	best_index;

	while (a)
	{
		best_index = LONG_MIN;
		current = b;
		while (current)
		{
			if (current->content < a->content \
			&& current->content > best_index)
			{
				best_index = current->content;
				target = current;
			}
			current = current->next;
		}
		if (best_index == LONG_MIN)
			a->target_node = find_bigger(b);
		else
			a->target_node = target;
		a = a->next;
	}
}
// FONCTION OK !
static void	cost_analysis(t_list *a, t_list *b)
{
	int		len_a;
	int		len_b;

	len_a = ft_lstsize(a);
	len_b = ft_lstsize(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->above_median))
			a->push_cost = len_a - (a->index);
		if (a->target_node->above_median)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += len_b - (a->target_node->index);
		a = a->next;
	}
}
// FONCTION OK !
void	set_cheapest(t_list *a)
{
	long	cheapest_value;
	t_list	*cheapest_node;

	if (!a)
		return ;
	cheapest_value = LONG_MAX;
	while (a)
	{
		if (a->push_cost < cheapest_value)
		{
			cheapest_value = a->push_cost;
			cheapest_node = a;
		}
		a = a->next;
	}
	cheapest_node->cheapest = true;
}

/* *************************** */
/* 			NOTE PROJECT		*/
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