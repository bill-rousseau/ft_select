/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st_putcirc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by birousse          #+#    #+#             */
/*   Updated: 2014/04/30 17:43:29 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftselect.h"

static void		ft_st_putcirc_infos(int argc, t_choice **choice, int y)
{
	int					nbr;
	char				*tty;
	char				*tmp;

	ft_st_cmdgoto(3, y);
	nbr = ft_st_putchoice(argc, choice, 0);
	ft_printf_fd("\033[0m%d selected ", isatty(STDOUT_FILENO), nbr);
	if ((tmp = ttyname(isatty(STDOUT_FILENO))) != NULL)
	{
		tmp = ft_strdup(tmp);
		tty = !ft_strncmp(tmp, "/dev/", 4) ? tmp + 5 : tmp;
		ft_st_cmdgoto(ft_st_termsize(0) - ft_strlen(tty) - 3, y);
		ft_putstr_fd(tty, isatty(STDOUT_FILENO));
		free(tmp);
	}
	return ;
}

static int		ft_st_putcirc_decal(int argc, t_choice **choice)
{
	int					ret;

	ret = (argc < ft_st_termsize(1)) ? (ft_st_termsize(1) - argc) / 2 : 0;
	ret += (ft_st_termsize(1) % 2) ? 1 : 0;
	ft_st_putcirc_infos(argc, choice, ret - 1);
	ft_st_cmdgoto((ft_st_termsize(0) - 24) / 2, ret - 1);
	ft_putstr_fd("Multi Selector by Bill", isatty(STDOUT_FILENO));
	ft_st_cmdgoto(1, ret);
	ft_putstr_fd("\033[2;49;90m", isatty(STDOUT_FILENO));
	ft_putchar_fd('/', isatty(STDOUT_FILENO));
	ft_putchar_loop_fd('=', isatty(STDOUT_FILENO), ft_st_termsize(0) - 4);
	ft_putchar_fd('\\', isatty(STDOUT_FILENO));
	ft_putstr_fd("\033[0;49;39m", isatty(STDOUT_FILENO));
	ft_st_cmdgoto(1, ret + argc);
	ft_putstr_fd("\033[2;49;90m", isatty(STDOUT_FILENO));
	ft_putchar_fd('\\', isatty(STDOUT_FILENO));
	ft_putchar_loop_fd('=', isatty(STDOUT_FILENO), ft_st_termsize(0) - 4);
	ft_putchar_fd('/', isatty(STDOUT_FILENO));
	ft_putstr_fd("\033[0;49;39m", isatty(STDOUT_FILENO));
	return (ret + 1);
}

static void		ft_st_style(int argc, t_choice **choice, int pos)
{
	int					i;
	int					j;
	int					col;
	static int			decal;

	i = -1;
	decal = ft_st_putcirc_decal(argc, choice);
	while (++i < ft_st_termsize(1) && !(j = 0))
	{
		col = i;
		ft_st_cmdgoto(0, i + decal);
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
			col = i + (++j * ft_st_termsize(1));
		}
	}
	return ;
}

static int		ft_st_resize(int *ac, t_choice ***ch, int **ps, t_putmenu **s)
{
	int					ret;

	ret = 0;
	if (*ch == NULL)
	{
		if (*s == NULL)
			ft_st_signal(0);
		*ac = (*s)->argc;
		*ps = (*s)->pos;
		*ch = (*s)->choice;
		ft_st_clear();
		ret = 1;
	}
	else
	{
		if (*s == NULL && (ret = 1))
			*s = (t_putmenu *)malloc(sizeof(t_putmenu));
		(*s)->argc = *ac;
		(*s)->pos = *ps;
		(*s)->choice = *ch;
	}
	return (ret);
}

void			ft_st_putcirc(int argc, t_choice **choice, int *pos, int key)
{
	int					leny;
	static t_putmenu	*size;

	ft_st_caption(0, 1);
	ft_st_resize(&argc, &choice, &pos, &size);
	if ((*choice)->str == NULL)
		ft_st_signal(1);
	ft_st_color(NULL, key, 0, 0);
	leny = ft_st_termsize(1);
	ft_st_check(argc, key, choice, pos);
	if (ft_st_decal(argc, leny))
	{
		ft_st_putmenu(argc, choice, *pos, key);
		return ;
	}
	ft_st_style(argc, choice, *pos);
	ft_st_caption(key, 0);
	return ;
}
