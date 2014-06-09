/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:22:20 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	int		i;
	char	*s2;

	i = -1;
	s2 = (char *)malloc(sizeof(char) * (len + 1));
	if (s == NULL || s2 == NULL)
		return (NULL);
	while (++i < (int)len)
		*(s2 + i) = (char)*(s + (start + i));
	*(s2 + i) = '\0';
	return (s2);
}
