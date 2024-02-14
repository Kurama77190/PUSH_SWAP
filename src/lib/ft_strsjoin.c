/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:29:39 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/14 13:31:28 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_strjoin(char **argv)
{
	int	i;
	int	j;
	int	index_join;
	char *join;

	i = 1;
	index_join = 0;
	join = malloc(sizeof(char) + (ft_argvlen(argv) * 2) + 1);
	if (!join)
		return (NULL);
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			join[index_join] = argv[i][j];
			index_join++;
			j++;
		}
		join[index_join] = ' ';
		index_join++;
		i++;
	}
	join[index_join] = '\0';
	return (join);
}
