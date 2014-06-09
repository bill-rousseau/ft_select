/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_loop_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/21 08:56:14 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:16:41 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes a character to the console several times
*/

void	ft_putchar_loop_fd(char c, int fd, int nbr)
{
	char	*ptr;

	ptr = (char *)malloc(sizeof(char) * (nbr + 1));
	*(ptr + nbr) = '\0';
	ft_memset(ptr, c, nbr);
	ft_putstr_fd(ptr, fd);
	return ;
}
