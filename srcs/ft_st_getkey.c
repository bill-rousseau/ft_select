/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st_getkey.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:28:12 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftselect.h"

static void		ft_st_getkey_debug(char *str)
{
	if (DEBUG)
	{
		ft_printf("-[%d:%d:%d:%d]-", str[0], str[1], str[2], str[3]);
		ft_st_signal(0);
	}
	return ;
}

int				ft_st_getkey(char *str)
{
	int		ret;

	ft_st_getkey_debug(str);
	ret = (str[0] == 9 && str[1] == 0 && str[2] == 0) ? GKEY_TAB : -1;
	ret = (str[0] == 10 && str[1] == 0 && str[2] == 0) ? GKEY_RTN : ret;
	ret = (str[0] == 27 && str[1] == 0 && str[2] == 0) ? GKEY_ESC : ret;
	ret = (str[0] == 32 && str[1] == 0 && str[2] == 0) ? GKEY_ESP : ret;
	ret = (str[0] == 42 && str[1] == 0 && str[2] == 0) ? GKEY_STAR : ret;
	ret = (str[0] == 43 && str[1] == 0 && str[2] == 0) ? GKEY_PLUS : ret;
	ret = (str[0] == 45 && str[1] == 0 && str[2] == 0) ? GKEY_MINUS : ret;
	ret = (str[0] == 46 && str[1] == 0 && str[2] == 0) ? GKEY_DOT : ret;
	ret = (str[0] == 47 && str[1] == 0 && str[2] == 0) ? GKEY_DIV : ret;
	ret = (str[0] == 48 && str[1] == 0 && str[2] == 0) ? GKEY_ZERO : ret;
	ret = (str[0] == 127 && str[1] == 0 && str[2] == 0) ? GKEY_BSP : ret;
	ret = (str[0] == 27 && str[1] == 91 && str[2] == 65) ? GKEY_UP : ret;
	ret = (str[0] == 27 && str[1] == 91 && str[2] == 66) ? GKEY_DOWN : ret;
	ret = (str[0] == 27 && str[1] == 91 && str[2] == 67) ? GKEY_RIGHT : ret;
	ret = (str[0] == 27 && str[1] == 91 && str[2] == 68) ? GKEY_LEFT : ret;
	if (ret != -1 && str[3] != 0)
		return (-1);
	else if (ret == -1 && str[3] == 126)
		ret = (str[0] == 27 && str[1] == 91 && str[2] == 51) ? GKEY_DEL : ret;
	return (ret);
}
