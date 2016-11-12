/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 12:55:59 by zsmith            #+#    #+#             */
/*   Updated: 2016/10/05 15:48:38 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *cont, size_t content_size)
{
	t_list	*tnew;

	tnew = (t_list *)malloc(sizeof(t_list));
	if (!tnew)
		return (NULL);
	if (cont == NULL)
	{
		tnew->content = NULL;
		tnew->content_size = 0;
	}
	else
	{
		tnew->content = malloc(content_size);
		if (tnew->content == NULL)
			return (NULL);
		ft_memcpy(tnew->content, cont, content_size);
		tnew->content_size = content_size;
	}
	tnew->next = NULL;
	return (tnew);
}
