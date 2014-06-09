/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:34:40 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:25:16 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_printf.h"

int		ft_printf_fd(const char *format, int fd, ...)
{
	va_list		ap;
	char		*ptr;
	size_t		len;

	len = 0;
	ptr = (char *)format;
	va_start(ap, fd);
	while (*ptr && (len += ft_get_v_arg(ap, &ptr, fd)))
		;
	va_end(ap);
	return ((int)len);
}
