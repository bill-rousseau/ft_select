/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:09:19 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstcmp(t_list *lst, char *str)
{
	int		len;
	int		start;

	if (lst == NULL || str == NULL)
		return (NULL);
	start = 0;
	len = ft_strlen(str);
	while (!start++ || ((lst = lst->next) != NULL && lst->content != NULL))
	{
		if (!ft_memcmp(lst->content, str, len - 1))
			return (lst);
	}
	return (NULL);
}
