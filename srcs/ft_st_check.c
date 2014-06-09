/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 07:02:52 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:26:10 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftselect.h"

static int	ft_st_check_move(int key, t_choice **choice, int pos)
{
	int		ok;
	int		check;
	char	*str;

	ok = 0;
	str = (*choice + (pos + 1))->str;
	check = (*choice + (pos + 1))->check;
	if (key == GKEY_PLUS && (*choice + (pos + 1))->str != NULL && (ok = 1))
	{
		(*choice + (pos + 1))->str = (*choice + pos)->str;
		(*choice + (pos + 1))->check = (*choice + pos)->check;
	}
	else if (key == GKEY_MINUS && pos > 0 && (ok = 1))
	{
		str = (*choice + (pos - 1))->str;
		check = (*choice + (pos - 1))->check;
		(*choice + (pos - 1))->str = (*choice + pos)->str;
		(*choice + (pos - 1))->check = (*choice + pos)->check;
	}
	if (ok && str != NULL)
	{
		(*choice + pos)->str = str;
		(*choice + pos)->check = check;
	}
	return (ok);
}

static int	ft_st_check_overflow(int argc, int key, int pos, int pos2)
{
	int		cols;
	int		lines;

	cols = ft_st_columns(argc + 1);
	lines = ft_st_termsize(1);
	if (ft_st_decal(argc, lines))
		lines--;
	if (key == 0 && ft_st_columns(pos + 1) < cols)
	{
		if ((pos + lines) >= argc && (pos % lines) == (lines - 1))
			pos2 -= lines;
	}
	else if (key == 1 && !pos)
		pos2 = argc - 1;
	else if (key == 1 && pos == 1 && (argc % lines) == 1)
		pos2 += lines;
	return (pos2);
}

static int	ft_st_check_target(int argc, int key, int *pos)
{
	int		cols;
	int		pos2;
	int		lines;

	if (key != GKEY_RIGHT && key != GKEY_LEFT)
		return (0);
	cols = ft_st_columns(argc);
	lines = ft_st_termsize(1);
	if (ft_st_decal(argc, lines))
		lines--;
	if (argc > lines)
	{
		pos2 = *pos + ((cols - 1) * lines) - 1;
		if (key == GKEY_RIGHT && (*pos + lines) < argc)
			*pos += lines;
		else if (key == GKEY_RIGHT)
			*pos = ft_st_check_overflow(argc, 0, *pos, *pos % lines + 1);
		else if (key == GKEY_LEFT && *pos - lines >= 0)
			*pos -= lines;
		else if (key == GKEY_LEFT)
			*pos = ft_st_check_overflow(argc, 1, *pos, pos2);
	}
	return (1);
}

void		ft_st_check(int argc, int key, t_choice **choice, int *pos)
{
	int		i;

	i = -1;
	if (ft_st_check_target(argc - 1, key, pos))
		return ;
	while ((key == GKEY_STAR || key == GKEY_DIV) && (*choice + (++i))->str)
		(*choice + i)->check = (key == GKEY_STAR) ? 1 : 0;
	while ((key == GKEY_PLUS || key == GKEY_MINUS) && (*choice + (++i))->str)
	{
		if (i == *pos)
		{
			if (ft_st_check_move(key, choice, *pos))
				*pos += (key == GKEY_PLUS) ? 1 : -1;
			break ;
		}
	}
	if (key == GKEY_ESP || key == GKEY_DEL || key == GKEY_BSP)
	{
		if (key != GKEY_ESP)
			ft_st_clear();
	}
	return ;
}
