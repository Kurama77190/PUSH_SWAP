/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:46:19 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/09 16:46:11 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool 	ft_is_digit(char **split);
int		ft_strcmp(char *s1, char *s2);
bool	ft_is_double(char **split);

//----------------------------------------------------
// IMPLEMENTE SECURITY
//----------------------------------------------------

bool	ft_secure(char **split)
{
	if(!ft_is_digit(split))
	{
		free(split);
		ft_exit();
		return false;
	}	
	else
		return true;
}

bool ft_is_digit(char **split)
{
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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

bool ft_is_double(char **split)
{
    int	i;
	int	j;

	i = 0;
    while (split[i])
	{
        j = i + 1;
        while (split[j])
		{
            if (ft_strcmp(split[i], split[j]) == 0)
                return true;
            j++;
        }
        i++;
    }
    return false;
}
//----------------------------------------------------
//IMPLEMENTE STACK_A
//-----------------------------------------------------
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
	char **split_a;
	t_list *stack_a;
	int	i;

	i = 0;
	split_a = ft_split(argv[1], ' ');
	stack_a = ft_lstnew(ft_atoi(split_a[i]));
	while(split_a[++i])
	{
		ft_lstadd_back(&stack_a, ft_lstnew(ft_atoi(split_a[i])));
	}
	ft_secure(split_a);
	free(split_a);
	return (stack_a);
}

int main(int argc, char **argv)
{
	(void)argc;
	t_list *a = implemente_a(argc, argv);
	ft_print_list(a);
}