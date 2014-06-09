/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/29 10:31:17 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:20:16 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfsub(char **s, unsigned int start, size_t len, int pfree)
{
	char		*ret;

	ret = ft_strsub((const char *)*s, start, len);
	if (pfree)
	{
		free(*s);
		*s = NULL;
	}
	return (ret);
}
