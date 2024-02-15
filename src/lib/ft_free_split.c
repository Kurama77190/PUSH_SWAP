/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 22:51:00 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/15 22:51:22 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
