/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/21 08:56:14 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:17:17 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writing a number in the console
*/

void	ft_putnbr_fd(int n, int fd)
{
	char	*tmp;

	if ((tmp = ft_itoa(n)))
	{
		ft_putstr_fd(tmp, fd);
		ft_strdel(&tmp);
	}
	else
		ft_putchar_fd('0', fd);
	return ;
}
