/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_f.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 01:47:01 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:24:50 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

char	*ft_pf_f(va_list ap, char *opts, int *ret)
{
	char	*str;

	if (opts == NULL)
		return (ft_strnew(0));
	str = ft_ftoa(va_arg(ap, double));
	*ret = ft_strlen(str);
	return (str);
}
