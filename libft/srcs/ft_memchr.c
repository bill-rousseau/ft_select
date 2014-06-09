/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:45:03 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:15:39 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*sb;

	i = 0;
	sb = (char *)s;
	while (++i <= n)
	{
		if (*(sb + (i - 1)) == (unsigned char)c)
			return (sb + (i - 1));
	}
	return (NULL);
}
