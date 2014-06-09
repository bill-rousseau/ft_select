/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st_columns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/03 05:38:17 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:26:52 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftselect.h"

int		ft_st_columns(int rows)
{
	int		ret;
	int		lines;

	ret = 1;
	lines = ft_st_termsize(1);
	if (ft_st_decal(rows, lines))
		lines--;
	rows -= lines;
	while (rows > lines && ++ret)
		rows -= lines;
	ret += rows > 1 ? 1 : 0;
	return (ret);
}
