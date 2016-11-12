/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zs_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 11:47:50 by zsmith            #+#    #+#             */
/*   Updated: 2016/09/27 15:25:10 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*t;

	t = s;
	i = 0;
	if (n == 0)
		return (t);
	while (i < n)
	{
		*t = (unsigned char)c;
		t++;
		i++;
	}
	return (s);
}
