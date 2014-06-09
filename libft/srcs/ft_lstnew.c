/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: birousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/26 04:36:20 by birousse          #+#    #+#             */
/*   Updated: 2014/04/29 14:10:04 by birousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list	*ret;

	ret = (t_list *)malloc(sizeof(t_list));
	if (ret != NULL)
	{
		if (content != NULL)
		{
			ret->content = ft_memalloc(content_size);
			ft_memcpy(ret->content, content, content_size);
		}
		else
			ret->content = NULL;
		ret->content_size = (ret->content != NULL) ? content_size : 0;
		ret->next = NULL;
	}
	return (ret);
}
