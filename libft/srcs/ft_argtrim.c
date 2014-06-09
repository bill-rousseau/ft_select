/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/25 23:14:21 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:06:39 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_argtrim(char **str)
{
	int		len;

	if (str == NULL || *str == NULL || **str == '\0')
		return ;
	len = ft_strlen(*str) - 1;
	if (**str == '"' && *(*str + len) == '"')
	{
		*(*str + len) = '\0';
		*str += 1;
	}
	return ;
}
