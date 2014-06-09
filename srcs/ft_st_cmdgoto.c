/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st_cmdgoto.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:26:29 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftselect.h"

int		ft_st_cmdgoto(int x, int y)
{
	char	*ptr;
	char	*ptr2;

	if ((ptr = tgetstr("cm", NULL)) != NULL)
	{
		if ((ptr2 = tgoto(ptr, x, y)) != NULL)
			ft_putstr_fd(ptr2, isatty(STDOUT_FILENO));
	}
	return (1);
}
