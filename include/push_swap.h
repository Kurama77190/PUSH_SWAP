/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:30:58 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/14 00:18:44 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <stdbool.h>

# include "../external/PRINTF/ft_printf.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
 	struct s_list	*prev;
}					t_list;

char	*ft_strjoin(char **argv);

size_t ft_argvlen(char **strs);

bool	ft_check_overflow(char *str, long long nb, int sign, size_t len);

bool    ft_atoi_overflow(char *str);

bool	ft_is_atoi_overflow(char **strs);

bool	ft_is_digit(char **split);

bool	ft_is_double(t_list	*stack_a);

int		ft_atoi(char *str);

void	ft_exit(void);

char	**ft_split(char const *s, char c);

void	ft_swap(int *a, int *b);

t_list	*ft_lstlast(t_list *lst);

void	ft_lstadd_back(t_list **alst, t_list *new);

void	ft_print_list(t_list *test);

void	ft_lstadd_front(t_list **lst, t_list *new);

t_list	*ft_lstnew(int content);

void	ft_putstr_fd(char *s, int fd);

#endif
