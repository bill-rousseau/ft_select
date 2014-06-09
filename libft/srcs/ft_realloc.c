/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:17:53 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	char	*s;

	s = NULL;
	if (ptr != NULL || size > 0)
		s = (char *)malloc(size);
	if (s == NULL)
		return (NULL);
	if (ptr != NULL)
	{
		free(ptr);
		ft_memcpy(s, ptr, ft_strlen(ptr));
	}
	return (s);
}
