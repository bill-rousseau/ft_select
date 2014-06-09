/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st_choice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:26:16 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftselect.h"

t_choice	*ft_st_choice(int argc, char **argv)
{
	t_choice	*choice;

	choice = (t_choice*)malloc(sizeof(t_choice) * ++argc);
	while (argc--)
	{
		(choice + argc)->str = (argc >= 0) ? *(argv + argc) : NULL;
		(choice + argc)->check = 0;
	}
	return (choice);
}
