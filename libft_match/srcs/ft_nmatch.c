/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmatch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/24 21:37:44 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:24:08 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_nmatch(char *s1, char *s2)
{
	if (!*s1 && !*s2)
		return (1);
	else if ((*s2 == '*' && !*s1))
		return (ft_nmatch(s1, (s2 + 1)));
	else if (*s2 == '*' && *s1)
		return (ft_nmatch((s1 + 1), s2) + ft_nmatch(s1, (s2 + 1)));
	else if (*s1 == *s2 && *s1)
		return (ft_nmatch((s1 + 1), (s2 + 1)));
	return (0);
}
