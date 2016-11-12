/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tab_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 10:44:19 by zsmith            #+#    #+#             */
/*   Updated: 2016/10/05 15:46:25 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** takes an input char table and converts it into a chained list
** address of the first element is returned
** note first element in list will be the last (head) element in the list
*/

#include "libft.h"

t_list	*ft_tab_to_list(char **str)
{
	t_list	*lst;
	t_list	*item;
	int		sz;

	item = ft_lstnew(*str, ft_strlen(*str));
	lst = item;
	str++;
	while (*str)
	{
		sz = ft_strlen(*str);
		item = ft_lstnew(*str, sz);
		ft_lstadd(&lst, item);
		str++;
	}
	return (item);
}
