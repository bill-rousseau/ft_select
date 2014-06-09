/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 13:42:17 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:05:41 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# include <stdarg.h>

# include "libft.h"
# include "t_v_arg.h"

/*
** Functions of ft_printf
*/

size_t		ft_get_v_arg(va_list ap, char **format, int fd);
char		*ft_pf_c(va_list ap, char *opts, int *ret);
char		*ft_pf_d(va_list ap, char *opts, int *ret);
char		*ft_pf_f(va_list ap, char *opts, int *ret);
char		*ft_pf_s(va_list ap, char *opts, int *ret);
char		*ft_pf_x(va_list ap, char *opts, int *ret);
int			ft_printf(const char *format, ...);
int			ft_printf_fd(const char *format, int fd, ...);
int			ft_printf_arg(va_list ap, char *format, char **out);
char		*ft_set_v_arg(const char *format, t_v_arg **init);
t_v_arg		*ft_v_arg_new();

#endif
