/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttlist.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/02 13:51:53 by zsmith            #+#    #+#             */
/*   Updated: 2016/10/05 15:47:11 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttlist(t_list *t)
{
	int		i;

	if (!t)
		ft_putstr("*t = NULL\n");
	i = 0;
	while (t)
	{
		ft_putstr("[");
		ft_putstr(t->content);
		ft_putstr("]");
		t = t->next;
		if (t)
			ft_putstr(" => ");
		i++;
	}
	ft_putstr("\n");
}
