/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:46:19 by sben-tay          #+#    #+#             */
/*   Updated: 2024/03/06 20:40:34 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			three_sort(&a);
		else
			ft_push_swap(&a, &b);
	}
	ft_lstclear(&a);
	ft_lstclear(&b);
}

/* *************************** */
/* 			NOTE PROJECT		*/
/* *************************** */

/*
	- PARSING SECURITY OK !
	- MEMORY MANAGEMENT OK !
	- SEGCHECK OK !
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

======================================================================================================================

	return 'n' size of instructions for sorting 'x' number values:

	if x 3 then n <= 3
	if x 5 then n <= 12
	if x 100 then n < 700
	if x 500 then n < 5500

	RANDOM GENERATOR URL : https://www.calculatorsoup.com/calculators/statistics/random-number-generator.php
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