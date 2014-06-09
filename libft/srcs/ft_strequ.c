/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:19:50 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(const char *s1, const char *s2)
{
	size_t	len;
	size_t	len2;

	if (s1 == NULL || s2 == NULL)
		return (0);
	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len = (len < len2) ? len2 : len;
	return (ft_strnequ(s1, s2, len));
}
