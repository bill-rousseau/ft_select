/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:28:19 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftselect.h"

static int		ft_st_init_deleg(char *str)
{
	ft_putstr_fd("ft_select: ", STDERR_FILENO);
	if (str != NULL)
		ft_putendl_fd(str, STDERR_FILENO);
	return (1);
}

int				ft_st_init(void)
{
	int		ret;
	int		success;
	char	*err;
	char	*termtype;

	ret = 0;
	termtype = getenv("TERM");
	if (termtype == NULL && (ret = 1))
		ft_st_init_deleg("specify a terminal type with `setenv TERM'.");
	success = ret ? 0 : tgetent(NULL, termtype);
	if (success < 0 && (ret = 1))
		ft_st_init_deleg("could not access the termcap data base.");
	if (success == 0 && (ret = ft_st_init_deleg(NULL)))
	{
		err = ft_strdup("terminal type `%s' is not defined.\n");
		ft_printf_fd(err, STDERR_FILENO, termtype);
		free(err);
	}
	return (ret);
}
