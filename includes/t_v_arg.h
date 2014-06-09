/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_v_arg.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/21 03:15:30 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:05:49 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_V_ARG_H
# define T_V_ARG_H

typedef struct		s_v_arg
{
	int				i;
	char			c;
	char			*s;
	int				type;
	struct s_v_arg	*next;
}					t_v_arg;

#endif
