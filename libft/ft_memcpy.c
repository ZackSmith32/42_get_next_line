/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 16:21:49 by zsmith            #+#    #+#             */
/*   Updated: 2016/09/24 22:28:02 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*strt;
	unsigned char	*end;

	strt = (unsigned char*)src;
	end = (unsigned char*)dest;
	i = 0;
	while (i < n)
	{
		*end = *strt;
		i++;
		end++;
		strt++;
	}
	return (dest);
}
