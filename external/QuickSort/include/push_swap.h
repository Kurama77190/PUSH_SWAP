/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 19:30:58 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/22 15:27:27 by sben-tay         ###   ########.fr       */
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
	struct s_list	*next;
 	struct s_list	*prev;
	int				content;
	int				index;
	int				flag;
}					t_list;

typedef struct s_push
{
	int				next;
	int				max;
	int				mid;
	int				flag;
}					t_push;

void	ft_push_swap(t_list **a, t_list **b);
void	reverse_rotate_a(t_list **a, bool flag);
void	reverse_rotate_b(t_list **b, bool flag);
void	reverse_rotate_rrr(t_list **a, t_list **b);
void	rotate_rr(t_list **a, t_list **b);
void	rotate_a(t_list **a, bool flag);
void	rotate_b(t_list **b, bool flag);
void	push_b(t_list **a, t_list **b, bool flag);
void	push_a(t_list **a, t_list **b, bool flag);
void	swap_ss(t_list **a, t_list **b);
void	swap_b(t_list **b, bool flag);
void	swap_a(t_list **a, bool flag);
void	print_commands(char *str, bool flag);
bool	is_sorted(t_list *stack_a);
void	ft_sortlist(t_list *a);
void	free_split(char **strs);
t_list	*implemente_a(int argc, char **argv);
char	*ft_strjoin(char **argv);
size_t	ft_argvlen(char **strs);
size_t  ft_lstsize(t_list *lst);
bool	ft_check_overflow(char *str, long long nb, int sign, size_t len);
bool    ft_atoi_overflow(char *str);
bool	ft_is_atoi_overflow(char **strs);
bool	ft_is_digit(char **split);
bool	ft_is_double(t_list	*stack_a);
bool	ft_is_space(char c);
bool	ft_only_space(char **strs);
bool	args_is_null(char **strs);
int		ft_atoi(char *str);
char	**ft_split(char const *s);
void	ft_swap(int *a, int *b);
void    ft_lstclear(t_list **lst);
void	ft_lstadd_back(t_list **alst, t_list *nw);
void	ft_print_list(t_list *test);
void	ft_lstadd_front(t_list **lst, t_list *nw);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstnew(int content);
t_list	*ft_lstcopy(t_list *lst);
void	ft_putstr_fd(char *s, int fd);
void	ft_secure_memory(char **split, t_list *stack_a);
void	ft_secure_arguments(char **argv);
void	ft_clear_error(char **split, t_list **stack_a);
void	ft_exit(void);

#endif
