/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 01:47:01 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:24:55 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

char	*ft_pf_s(va_list ap, char *opts, int *ret)
{
	char	*str;

	if (opts == NULL)
		return (ft_strnew(0));
	str = va_arg(ap, char *);
	if (str == NULL)
	{
		*ret = 6;
		return (ft_strdup("(null)"));
	}
	*ret = ft_strlen(str);
	return (ft_strdup(str));
}
