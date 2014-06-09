/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st_putmenu.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:28:35 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftselect.h"

static void		ft_st_infos(int argc, t_choice **choice)
{
	int					leny;
	int					nbr;
	char				*tmp;
	char				*tty;

	leny = ft_st_termsize(1);
	ft_st_cmdgoto(0, leny - 1);
	ft_st_cmdput("mr");
	ft_putstr_fd("\033[2;49;90m", isatty(STDOUT_FILENO));
	ft_putchar_loop_fd(' ', isatty(STDOUT_FILENO), ft_st_termsize(0));
	ft_st_cmdgoto(0, leny - 1);
	nbr = ft_st_putchoice(argc, choice, 0);
	ft_printf_fd(" %d selected ", isatty(STDOUT_FILENO), nbr);
	ft_st_cmdgoto((ft_st_termsize(0) - 24) / 2, leny - 1);
	ft_putstr_fd("Multi Selector by Nalvin", isatty(STDOUT_FILENO));
	if ((tmp = ttyname(isatty(STDOUT_FILENO))) != NULL)
	{
		tmp = ft_strdup(tmp);
		tty = !ft_strncmp(tmp, "/dev/", 4) ? tmp + 5 : tmp;
		ft_st_cmdgoto(ft_st_termsize(0) - ft_strlen(tty) - 1, leny - 1);
		ft_putstr_fd(tty, isatty(STDOUT_FILENO));
		free(tmp);
	}
	ft_putstr_fd(" \033[0;49;39m", isatty(STDOUT_FILENO));
	ft_st_cmdput("me");
}

void			ft_st_putmenu(int argc, t_choice **choice, int pos, int key)
{
	int					i;
	int					j;
	int					col;

	if ((i = -1) == -1 && (*choice)->str == NULL)
		ft_st_signal(1);
	while (++i < (ft_st_termsize(1) - 1) && !(j = 0))
	{
		col = i;
		ft_st_cmdgoto(0, i);
		while (i < argc && col < argc - 1 && (*choice + col)->str != NULL)
		{
			ft_st_cmdput("me");
			ft_st_color((*choice + col)->str, 0, col, pos);
			if ((*choice + col)->check)
				ft_st_cmdput("mr");
			if (!ft_st_putstr((*choice + col)->str, argc, col, pos))
				return ;
			ft_st_cmdput("me");
			ft_putstr_fd("\033[0m", isatty(STDOUT_FILENO));
			col = i + (++j * (ft_st_termsize(1) - 1));
		}
	}
	ft_st_infos(argc, choice);
	ft_st_caption(key, 0);
}
