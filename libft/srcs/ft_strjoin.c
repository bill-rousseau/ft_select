/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:20:51 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		i;
	int		len;
	char	*s3;

	i = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1);
	s3 = (char *)malloc(sizeof(char) * (len + ft_strlen(s2) + 1));
	if (s3 == NULL)
		return (NULL);
	ft_strcpy(s3, s1);
	ft_strcpy(s3 + len, s2);
	return (s3);
}
