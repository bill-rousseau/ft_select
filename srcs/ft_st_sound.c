/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st_sound.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 05:56:35 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:29:01 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftselect.h"

int		ft_st_sound(int key)
{
	if (key == GKEY_ESP)
		ft_st_cmdput("bl");
	return (1);
}
