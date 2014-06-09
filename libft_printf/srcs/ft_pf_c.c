/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 01:47:28 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:24:42 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

char	*ft_pf_c(va_list ap, char *opts, int *ret)
{
	char	*str;

	if (opts == NULL)
		return (ft_strnew(0));
	str = ft_strnew(1);
	*str = (*opts == '%') ? '%' : va_arg(ap, int);
	*ret = 1;
	return (str);
}
