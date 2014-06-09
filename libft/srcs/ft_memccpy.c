/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:58:29 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:15:29 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	int		i;
	char	*s1b;
	char	*s2b;

	i = -1;
	s1b = (char *)s1;
	s2b = (char *)s2;
	while (++i < (int)n)
	{
		*(s1b + i) = *(s2b + i);
		if (*(s2b + i) == c)
			return (s1b + i + 1);
	}
	return (NULL);
}
