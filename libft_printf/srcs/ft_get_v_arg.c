/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_v_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:34:40 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:24:36 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

size_t	ft_get_v_arg(va_list ap, char **format, int fd)
{
	int		i;
	int		ret;
	char	*out;

	out = NULL;
	i = ft_strcchr(*format, '%');
	if (i == -1)
	{
		if ((i = ft_strlen(*format)))
			write(fd, *format, i);
		*format += i;
		return (i);
	}
	write(fd, *format, i);
	ret = ft_printf_arg(ap, (*format + i), &out);
	*format += i + 2;
	write(fd, out, ft_strlen(out));
	ft_strdel(&out);
	return (i + ret);
}
