/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_arg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/19 01:49:59 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:25:11 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

static int	ft_flag_return(char *str)
{
	int		i;

	i = -1;
	while (*(str + (++i)))
	{
		if (ft_isalpha(*(str + i)))
			break ;
	}
	return (i);
}

int			ft_printf_arg(va_list ap, char *format, char **out)
{
	int		ret;
	char	*opts;

	*out = NULL;
	if ((opts = ft_strsub(format, 1, ft_flag_return(format))) == NULL)
		return (0);
	*out = (*out || ft_strcmp(opts, "c")) ? *out : ft_pf_c(ap, opts, &ret);
	*out = (*out || ft_strcmp(opts, "%")) ? *out : ft_pf_c(ap, opts, &ret);
	*out = (*out || ft_strcmp(opts, "d")) ? *out : ft_pf_d(ap, opts, &ret);
	*out = (*out || ft_strcmp(opts, "f")) ? *out : ft_pf_f(ap, opts, &ret);
	*out = (*out || ft_strcmp(opts, "s")) ? *out : ft_pf_s(ap, opts, &ret);
	*out = (*out || ft_strcmp(opts, "x")) ? *out : ft_pf_x(ap, opts, &ret);
	*out = (*out || ft_strcmp(opts, "X")) ? *out : ft_pf_x(ap, opts, &ret);
	*out = (*out == NULL) ? ft_strnew(0) : *out;
	ft_strdel(&opts);
	return (ret);
}
