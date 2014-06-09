/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 00:30:43 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:21:55 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = (int)ft_strlen((char *)s) + 1;
	while (--i >= 0)
	{
		if (*(s + i) == c)
			return ((char *)s + i);
	}
	if (*(s + i) == c)
		return ((char *)s + i);
	return (NULL);
}
