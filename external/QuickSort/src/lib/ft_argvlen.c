/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argvlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sben-tay <sben-tay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 13:28:43 by sben-tay          #+#    #+#             */
/*   Updated: 2024/02/16 02:02:03 by sben-tay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_argvlen(char **strs)
{
	size_t	len;
	int		i;

	len = 0;
	i = 1;
	while (strs[i])
	{
		len = len + ft_strlen(strs[i]);
		i++;
	}
	return (len);
}
