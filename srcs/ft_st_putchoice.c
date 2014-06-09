/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st_putchoice.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:28:25 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftselect.h"

int		ft_st_putchoice(int argc, t_choice **choice, int print)
{
	int		i;
	int		start;

	i = -1;
	start = 0;
	while (++i < argc - 1 && (*choice + i)->str != NULL)
	{
		if ((*choice + i)->check)
		{
			if (start++ && print)
				ft_putchar(' ');
			if (print)
				ft_putstr((*choice + i)->str);
		}
	}
	if (start)
		ft_putchar('\n');
	return (start);
}
