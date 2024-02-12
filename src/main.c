/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:46:19 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/12 20:47:18 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(void);
bool 	ft_is_digit(char **split);
int		ft_strcmp(char *s1, char *s2);
bool	ft_is_double(t_list *stack_a);
void	free_split(char **strs);
bool	is_sorted(t_list *stack_a);
void    ft_lstclear(t_list **lst);

//----------------------------------------------------
// IMPLEMENTE SECURITY - PARSING
//----------------------------------------------------

// ajouter la verification des doublons dans la stack.

void	ft_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ft_secure(char **split, t_list *stack_a)
{
	if(!ft_is_digit(split))
	{
		free_split(split);
		ft_lstclear(&stack_a);
		ft_exit();
	}
	else if (ft_is_atoi_overflow(split))
	{
		free_split(split);
		ft_lstclear(&stack_a);
		ft_exit();
	}
	else if(ft_is_double(stack_a))
	{
		free_split(split);
		ft_lstclear(&stack_a);
		ft_exit();
	}
	else
		return ;
}


bool	ft_is_digit(char **split)
{
	if (!split)
	return false;
	int	i;
	int	j;

	i = 0;
	while (split[i])
	{
		j = 0;
		if (split[i][j] == '+' || split[i][j] == '-')
		{
			j++;
			if (split[i][j] == '\0')
				return false;
		}
		while (split[i][j])
		{
			if (split[i][j] < '0' || split[i][j] > '9')
				return false;
			j++;
		}
		i++;
	}
	return true;
}

bool	ft_is_double(t_list *stack_a)
{
	t_list	*current;
	t_list	*checker;

	current = stack_a;
	while (current && current->next)
	{
		checker = current->next;
		while (checker)
		{
			if (current->content == checker->content)
				return true;
			checker = checker->next;
		}
		current = current->next;
	}
	return false;
}

void	free_split(char **strs)
{
	if (!strs)
		return ;
	int	i;

	i = 0;
	while(strs[i])
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

void    ft_lstclear(t_list **lst)
{
    t_list  *current;
    t_list  *next;

    if (lst == NULL || *lst == NULL)
        return;

    current = *lst;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *lst = NULL;
}

//----------------------------------------------------
//IMPLEMENTE STACK_A
//-----------------------------------------------------

bool	is_sorted(t_list *stack_a)
{
	t_list	*sorted;

	sorted = stack_a;
	while(sorted->next)
	{
		if (sorted->content < sorted->next->content)
			sorted = sorted->next;
		else
			return false;
	}
	return true;
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t			i;
	size_t			j;
	char			*str;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

t_list *implemente_a(int argc, char **argv)
{
	(void)argc;
	char	**split_a;
	t_list	*stack_a;
	int		i;

	i = 0;
	split_a = ft_split(argv[1], ' ');
	stack_a = ft_lstnew(ft_atoi(split_a[i]));
	while(split_a[++i])
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(split_a[i])));
	}
	ft_secure(split_a, stack_a);
	free_split(split_a);
	return (stack_a);
}

// DERNIERE ETAPE : gerer le cas de plusieurs arguments pour implementer la stack_a
// NE PAS OUBLIER de rajouter les fonctions dans mon header

int main(int argc, char **argv)
{
	(void)argc;
	t_list *a = implemente_a(argc, argv);
	ft_print_list(a);
	ft_printf("le retour de ft_is_double : %d\n", ft_is_double(a));
	ft_lstclear(&a);
}
