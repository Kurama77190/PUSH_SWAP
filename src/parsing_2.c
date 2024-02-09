/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:30:58 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/09 15:30:45 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	pb (push b) : Prend le premier élément au sommet de a et le met sur b.
	Ne fait rien si a est vide.
*/

void	push_b(t_list **stack_a);


/*
	ra (rotate a) : Décale d’une position vers le haut tous les élements de la pile a.
	Le premier élément devient le dernier
*/

void	rotate_a(t_list **stack_a);


// /*
// 	rb (rotate b) : Décale d’une position vers le haut tous les élements de la pile b.
// 	Le premier élément devient le dernier.
// */

void	rotate_b(t_list **stack_b);


/*
	rr : ra et rb en même temps.
*/

void	rotate_rr(t_list **stack_a, t_list **stack_b);


/*
	rra (reverse rotate a) : Décale d’une position vers le bas tous les élements de
	la pile a. Le dernier élément devient le premier.
*/

void	reverse_rotate_a(t_list **stack_a);
