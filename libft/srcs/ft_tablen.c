/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 10:31:17 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:22:33 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tablen(char **arr)
{
	int		i;

	i = 0;
	if (arr == NULL || *arr == NULL)
		return (i);
	while (*(arr + i) != NULL)
		i++;
	return (i);
}
