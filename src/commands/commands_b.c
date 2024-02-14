/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:47:31 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/09 15:29:34 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	rrb (reverse rotate b) : Décale d’une position vers le bas tous les élements de
	la pile b. Le dernier élément devient le premier.
*/

void	reverse_rotate_b(t_list **stack_b);


/*
	rrr : rra et rrb en même temps.
*/

void	reverse_rotate_rrr(t_list **stack_a, t_list **stack_b);

