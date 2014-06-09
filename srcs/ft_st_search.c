/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_st_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <birousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/11 21:08:32 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:28:46 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftselect.h"

static int		ft_st_search_deleg(t_search **list, int key)
{
	int					ret;

	ret = -1;
	if (*list == NULL)
		return (ret);
	if (key == GKEY_RTN)
	{
		if ((*list)->str != NULL)
			free((*list)->str);
		free(*list);
		*list = NULL;
	}
	else if (key == GKEY_ESC && !(ret = 0))
	{
		if ((*list)->str != NULL)
			free((*list)->str);
		free(*list);
		*list = NULL;
	}
	return (ret);
}

static t_choice	*ft_st_search_while(t_choice **ch, char *str, int *nbr)
{
	char				*search;
	t_choice			*ptr;

	ptr = *ch;
	search = ft_strjoin("*", str);
	if (search && (search = ft_strfjoin1(&search, "*", 1)))
	{
		while ((*ch + *nbr)->str != NULL)
		{
			if (ft_match((*ch + *nbr)->str, search))
			{
				ptr = (*ch + *nbr);
				return (ptr);
			}
			*nbr += 1;
		}
	}
	if (search)
		free(search);
	*nbr = 0;
	return (ptr);
}

static t_search	*ft_st_search_create(t_choice **ch, char *str, int *nbr)
{
	t_search			*list;

	list = (t_search *)malloc(sizeof(t_search));
	list->str = ft_strtrim(str);
	list->nbr = *nbr;
	list->first = ft_st_search_while(ch, str, nbr);
	return (list);
}

int				ft_st_search(t_choice **o, t_search **t, char *c)
{
	int					nbr;
	int					key;
	char				*str;

	nbr = 0;
	str = ft_ctoa(*c);
	key = ft_st_getkey(c);
	ft_st_search_deleg(t, key);
	if (key != GKEY_RTN && key != GKEY_ESC)
	{
		if (*t == NULL && key == -1 && ft_isprint(*c) && *(c + 1) == 0)
			*t = ft_st_search_create(o, str, &nbr);
		else if (*t != NULL && (*t)->str != NULL)
		{
			if (key == GKEY_BSP && (nbr = ft_strlen((*t)->str)))
				(*t)->str = ft_strfsub(&(*t)->str, 0, nbr - 1, 1);
			else if (ft_strlen((*t)->str) < 10 && ft_isprint(*c))
				(*t)->str = ft_strfjoin1(&(*t)->str, str, 1);
			if (!(nbr = 0) && (*t)->str != NULL)
				(*t)->first = ft_st_search_while(o, (*t)->str, &(*t)->nbr);
		}
	}
	if (str != NULL)
		free(str);
	return (1);
}
