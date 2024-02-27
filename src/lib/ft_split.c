/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:58:37 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/27 16:26:39 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_nombremot(char *str);
static int	ft_lenmot(char *str);
static char	**ft_malloc_error(char **tab);
bool		ft_ajoutdesmots(char **tab, char *str, int i);

char	**ft_split(char const *s)
{
	char	*str;
	char	**tab;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	str = (char *)s;
	tab = malloc(sizeof(char *) * (ft_nombremot(str) + 1));
	if (!tab)
		return (NULL);
	ft_ajoutdesmots(tab, str, i);
	if (!ft_ajoutdesmots(tab, str, i))
	{
		ft_malloc_error(tab);
		return (NULL);
	}
	return (tab);
}

static int	ft_nombremot(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (ft_is_space(str[i]) && str[i])
			i++;
		if (str[i])
			count++;
		while (!ft_is_space(str[i]) && str[i])
			i++;
	}
	return (count);
}

static int	ft_lenmot(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !ft_is_space(str[i]))
		i++;
	return (i);
}

static char	**ft_malloc_error(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free (tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

bool	ft_ajoutdesmots(char **tab, char *str, int i)
{
	int	j;
	int	k;

	j = 0;
	while (str[i])
	{
		k = 0;
		while (ft_is_space(str[i]))
			i++;
		if (str[i])
		{
			tab[j] = malloc((sizeof(char)) * (ft_lenmot(str + i) + 1));
			if (!tab[j])
				return (false);
			while (str[i] && !ft_is_space(str[i]))
			{
				tab[j][k] = str[i];
				i++;
				k++;
			}
			tab[j][k] = '\0';
			j++;
		}
	}
	tab[j] = NULL;
	return (true);
}
