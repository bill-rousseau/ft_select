/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_center.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:29:16 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftselect.h"

char	*ft_str_center(char *str, size_t size)
{
	size_t	i;
	size_t	tmp;
	char	*ret;

	i = 0;
	tmp = (size - ft_strlen(str)) / 2;
	ret = (char *)malloc(sizeof(char) * (size + 1));
	ret[size] = '\0';
	ft_memset(ret, ' ', size);
	while (i++ < size && *str)
	{
		if (i > tmp)
			ret[i - 1] = *str++;
	}
	return (ret);
}
