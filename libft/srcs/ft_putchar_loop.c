/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_loop.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/21 08:56:14 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:23:27 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Writes a character to the console several times
*/

void	ft_putchar_loop(char c, int nbr)
{
	ft_putchar_loop_fd(c, STDIN_FILENO, nbr);
	return ;
}
