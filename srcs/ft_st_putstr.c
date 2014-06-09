/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st_putstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 19:46:25 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:28:40 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftselect.h"

static int		ft_st_cursor(char *str, int argc, int end)
{
	int		ret;
	int		len;

	len = ft_st_termsize(0) / ft_st_columns(argc);
	ret = (len - ft_strlen(str)) / 2;
	if (end)
		ret = len - (ret + ft_strlen(str));
	return (ret);
}

int				ft_st_putstr(char *str, int argc, int col, int pos)
{
	int		nbr;
	char	*p;

	if ((nbr = ft_st_cursor(str, argc, 0)) > 0)
		ft_putchar_loop_fd(' ', isatty(STDOUT_FILENO), nbr);
	else
	{
		ft_st_clear();
		nbr = ft_st_termsize(1) / 2;
		nbr -= (ft_st_termsize(1) % 2) ? 0 : 1;
		ft_st_cmdgoto((ft_st_termsize(0) - 36) / 2, nbr);
		p = ft_strdup("\033[49;31mWindow too small, too many arguments\033[0m");
		ft_putstr_fd(p, isatty(STDOUT_FILENO));
		free(p);
		return (0);
	}
	if (col == pos)
		ft_st_cmdput("us");
	ft_putstr_fd(str, isatty(STDOUT_FILENO));
	ft_st_cmdput("ue");
	if ((nbr = ft_st_cursor(str, argc, 1)) > 0)
		ft_putchar_loop_fd(' ', isatty(STDOUT_FILENO), nbr);
	return (1);
}
