/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/31 16:32:06 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:22:04 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strreplace(char *str, char c1, char c2)
{
	int		i;

	i = -1;
	while (*(str + (++i)))
	{
		if (*(str + i) == c1)
			*(str + i) = c2;
	}
	return ;
}
