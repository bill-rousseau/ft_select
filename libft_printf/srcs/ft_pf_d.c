/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 01:48:05 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:24:46 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

char	*ft_pf_d(va_list ap, char *opts, int *ret)
{
	char	*str;

	if (opts == NULL)
		return (ft_strnew(0));
	str = ft_itoa(va_arg(ap, int));
	*ret = ft_strlen(str);
	return (str);
}
