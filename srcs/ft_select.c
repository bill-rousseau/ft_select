/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:25:55 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftselect.h"

int			main(int argc, char **argv)
{
	t_search	*search;
	t_choice	*choice;

	if (argc <= 1 || ft_st_init())
	{
		if (argc <= 1)
			ft_putendl_fd("ft_select: Too few arguments.", STDERR_FILENO);
		return (-1);
	}
	search = NULL;
	choice = ft_st_choice(argc - 1, argv + 1);
	ft_st_signal(0);
	ft_st_cmdput("ti");
	ft_st_cmdput("cl");
	ft_st_caption(GKEY_ZERO, -1);
	if (ft_select(&choice, &search, &argc, 0) == GKEY_RTN)
	{
		ft_st_signal(-1);
		ft_st_putchoice(argc, &choice, 1);
	}
	else
		ft_st_signal(0);
	return (0);
}

static void	ft_select_deleg(t_choice **choice, int *argc, int key, int *pos)
{
	*pos += (key == GKEY_UP) ? -1 : 0;
	*pos += (key == GKEY_DOWN) ? 1 : 0;
	*pos = ((*pos < 0) ? *argc - 2 : *pos) % (*argc - 1);
	ft_st_putcirc(*argc, choice, pos, key);
	return ;
}

static int	ft_select_search(t_choice **ch, t_search **s, char *c, int *pos)
{
	int			key;
	int			ret;
	static int	save;

	ret = 0;
	save = (s == NULL && *s == NULL && (*s)->str == NULL) ? *pos : save;
	if (((key = ft_st_getkey(c)) == GKEY_UP || key == GKEY_STAR
		|| key == GKEY_LEFT || key == GKEY_RIGHT || key == GKEY_DIV
		|| key == GKEY_MINUS || key == GKEY_PLUS || key == GKEY_ZERO
		|| key == GKEY_RTN || key == GKEY_ESC || key == GKEY_DEL)
		&& (s != NULL && *s != NULL && (*s)->str != NULL))
	{
		if (*s != NULL && (*s)->str != NULL && (ret = 1))
			free((*s)->str);
		if (*s != NULL && (ret = 1))
			free(*s);
		if ((*s = NULL) == NULL && key == GKEY_ESC)
			*pos = save;
	}
	else if (ft_st_search(ch, s, c))
	{
		if (*s != NULL && (*s)->str != NULL && (*s)->nbr >= 0 && (ret = 1))
			*pos = (*s)->nbr;
	}
	return (ret);
}

static void	ft_select_search_view(t_search *list, int argc, int search)
{
	int			leny;

	if ((leny = ft_st_termsize(1)) && list != NULL && list->str != NULL)
	{
		if (ft_st_decal(argc, leny))
		{
			ft_st_cmdgoto(1, leny - 1);
			ft_st_cmdput("mr");
			ft_putstr_fd("\033[2;49;90m", isatty(STDOUT_FILENO));
		}
		else
		{
			leny = (argc < leny) ? (leny - argc) / 2 + (leny % 2) : 0;
			ft_st_cmdgoto(2, leny + argc + 1);
		}
		ft_printf_fd("search word : %s", isatty(STDOUT_FILENO), list->str);
		if (ft_strlen(list->str) < 10)
			ft_putchar_fd('_', isatty(STDOUT_FILENO));
	}
	else if (search)
	{
		ft_st_clear();
		ft_st_putcirc(0, NULL, NULL, 0);
	}
	return ;
}

int			ft_select(t_choice **ch, t_search **s, int *argc, int search)
{
	int			pos;
	int			key;
	char		*c;

	pos = 0;
	key = 0;
	ft_st_putcirc(*argc, ch, &pos, 0);
	while (ft_st_cmdgoto(0, 0) && (c = ft_getch()))
	{
		if (!(key = ft_st_getkey(c)))
			break ;
		search = ft_select_search(ch, s, c, &pos);
		if (c != NULL)
			free(c);
		if ((!search && key == GKEY_BSP) || key == GKEY_DEL)
			ft_st_delmenu(argc, ch, &pos);
		if (!search && (key == GKEY_ESC || key == GKEY_RTN))
			break ;
		else if (!search && key == GKEY_ESP && ft_st_sound(key) && ++pos)
			(*ch + (pos - 1))->check = ((*ch + (pos - 1))->check + 1) % 2;
		ft_select_deleg(ch, argc, key, &pos);
		ft_select_search_view(*s, *argc, search);
	}
	return (key);
}
