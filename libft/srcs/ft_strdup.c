/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/19 09:16:55 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:19:45 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;

	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (s2 == NULL)
		return (NULL);
	ft_strcpy(s2, (char *)s1);
	return (s2);
}
