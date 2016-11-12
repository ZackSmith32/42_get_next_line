/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 20:08:17 by zsmith            #+#    #+#             */
/*   Updated: 2016/10/03 19:30:27 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(f)(t_list *elem))
{
	t_list	*clst;
	t_list	*hold;

	hold = f(lst);
	clst = hold;
	if (!clst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		hold->next = f(lst);
		if (!hold)
			return (NULL);
		hold = hold->next;
	}
	return (clst);
}
