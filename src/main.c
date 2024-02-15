/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:46:19 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/15 23:59:33 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* *************************** */
/* 	 	MAIN PROGRAMME	 	   */
/* *************************** */

int main(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	ft_secure_arguments(argv);
	t_list *a = implemente_a(argc, argv);
	ft_print_list(a);
	ft_lstclear(&a);
}

/* *************************** */
/* 	 	  NOTE PROJECT	 	   */
/* *************************** */

/*
	- PARSING SECURITY 100% OK
	- NOW, I NEED IMPLEMENT ALGORITHM ! LETSGOOO
*/
