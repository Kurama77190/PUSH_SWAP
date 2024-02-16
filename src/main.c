/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:46:19 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/16 02:15:11 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* *************************** */
/* 		 MAIN PROGRAMME	       */
/* *************************** */

int	main(int argc, char **argv)
{
	t_list	*a;
	// t_list	*b;

	if (argc == 1)
		return (0);
	ft_secure_arguments(argv);
	a = implemente_a(argc, argv);
	ft_print_list(a);
	ft_lstclear(&a);
}

/* *************************** */
/* 	      NOTE PROJECT	       */
/* *************************** */

/*
	- PARSING SECURITY 100% OK
	- NOW, I NEED IMPLEMENT ALGORITHM ! LETSGOOO
*/

/* *************************** */
/* 		 COMMANDS TEST	       */
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