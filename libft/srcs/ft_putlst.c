/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:17:04 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putlst_reverse(t_list *lst, char *(*f)(int n), int i, int j)
{
	char	*ptr;

	if (lst->next != NULL)
		ft_putlst_reverse(lst->next, f, i + 1, j);
	if (lst->content != NULL)
	{
		ft_putchar('\r');
		ptr = f ? f((int)*((int *)lst->content)) : (char *)lst->content;
		if (j)
			ft_printf(" [\033[33m%d\033[0m] %s\n", i + 1, ptr);
		else
			ft_putendl(ptr);
	}
	return ;
}

void			ft_putlst(t_list *lst, char *(*f)(int n), int rev, int debug)
{
	int		start;
	char	*ptr;

	(void)debug;
	if (lst == NULL || lst->content == NULL)
		return ;
	if (!(start = 0) && rev)
	{
		ft_putlst_reverse(lst, f, 0, debug);
		return ;
	}
	while (!start++ || ((lst = lst->next) != NULL && lst->content != NULL))
	{
		ft_putchar('\r');
		ptr = f ? f((int)*((int *)lst->content)) : (char *)lst->content;
		if (debug)
			ft_printf(" [\033[33m%d\033[0m] %s\n", start - 1, ptr);
		else
			ft_putendl(ptr);
	}
	return ;
}
