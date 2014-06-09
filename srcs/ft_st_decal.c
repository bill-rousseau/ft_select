/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st_decal.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 04:13:40 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:26:57 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftselect.h"

int		ft_st_decal(int argc, int lines)
{
	int		decal;

	decal = (argc < lines) ? (lines - argc) / 2 : 0;
	decal += (lines % 2) ? 1 : 0;
	if (!(decal && argc < lines - 3 && ft_st_termsize(0) > 55))
		return (1);
	return (0);
}
