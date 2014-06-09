/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strftrim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:20:23 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strftrim(char **s, int pfree)
{
	char	*ret;

	ret = ft_strtrim(*s);
	if (pfree == 1)
	{
		free(*s);
		*s = NULL;
	}
	return (ret);
}
