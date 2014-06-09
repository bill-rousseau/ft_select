/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 00:30:43 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:19:01 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (*(s + (++i - 1)))
	{
		if (*(s + (i - 1)) == c)
			return ((char *)s + (i - 1));
	}
	if (*(s + (i - 1)) == c)
		return ((char *)s + (i - 1));
	return (NULL);
}