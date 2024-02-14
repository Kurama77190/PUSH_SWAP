/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:46:19 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/14 17:06:36 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* *************************** */
/* 	 	MAIN PROGRAMMER 	   */
/* *************************** */

/*								PARSING ERROR : 
 - Si un arguments est = NULL; -> Error;
 - les arguments separateur de mon split = isspace(char c) tester avec cette commande :


$./push_swap "             






7"

*/

int main(int argc, char **argv)
{
	if (argc == 1 || !argv[1][0])
		return (0);
	t_list *a = implemente_a(argc, argv);
	ft_print_list(a);
	ft_lstclear(&a);
}
