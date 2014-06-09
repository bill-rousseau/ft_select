/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/09 07:26:07 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:26:46 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftselect.h"

static void		ft_st_color_x(char *str)
{
	struct stat			sb;

	if (stat(str, &sb) >= 0)
	{
		if (!S_ISDIR(sb.st_mode) && (sb.st_mode & S_IXUSR))
			ft_putstr_fd("\033[31m", isatty(STDOUT_FILENO));
	}
	return ;
}

void			ft_st_color(char *str, int key, int i, int pos)
{
	char				*ptr;
	static int			active;

	if (key == GKEY_DOT)
		active = active ? 0 : 1;
	if (i == pos)
		return ;
	if (!active && str != NULL && !ft_strncmp(str, "/dev/", 4))
		ft_putstr_fd("\033[31m", isatty(STDOUT_FILENO));
	else if (!active && str != NULL && (ptr = ft_strrchr(str, '.')) != NULL)
	{
		if (!ft_strcmp(ptr, ".o"))
			ft_putstr_fd("\033[35m", isatty(STDOUT_FILENO));
		else if (!ft_strcmp(ptr, ".c"))
			ft_putstr_fd("\033[34m", isatty(STDOUT_FILENO));
		else if (!ft_strcmp(ptr, ".cpp"))
			ft_putstr_fd("\033[32m", isatty(STDOUT_FILENO));
		else if (!ft_strcmp(ptr, ".s"))
			ft_putstr_fd("\033[36m", isatty(STDOUT_FILENO));
		else if (!ft_strcmp(ptr, ".cor"))
			ft_putstr_fd("\033[33m", isatty(STDOUT_FILENO));
	}
	else if (!active && str != NULL && ptr == NULL)
		ft_st_color_x(str);
	return ;
}
