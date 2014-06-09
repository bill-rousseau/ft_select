/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 17:30:21 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:20:59 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *s1, const char *s2, size_t n)
{
	int		i;
	size_t	len;
	size_t	len2;

	i = -1;
	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (n < len)
		return (n + len2);
	while (*(s2 + (++i)) && *(s2 + i) && (i + (int)len) < (int)n - 1)
		*(s1 + len + i) = *(s2 + i);
	*(s1 + len + i) = '\0';
	return (len + len2);
}
