/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 15:46:19 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/06 17:29:10 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// verifier si il y a des doublons,
int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

bool ft_isdouble(char **tab_str)
{
	int i = 0;
	int j;
	while (tab_str[i])
	{
		j = 1;
		while(tab_str[j])
		{
			if (strcmp())	
		}
		i++;
	}
}

int main(void)
{
	char *a = "0";
	char *b = "10";
	char *c = "2";
	char *d = "5";
	char *e = "10";

	ft_printf("voici mon retour : %d\n", ft_strcmp(b, e));
	ft_printf("voici mon retour : %d\n", ft_strcmp(a, c));
	ft_printf("voici mon retour : %d\n", ft_strcmp(b, d));
}
