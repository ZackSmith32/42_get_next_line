/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 17:14:11 by zsmith            #+#    #+#             */
/*   Updated: 2016/09/24 22:40:12 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src,
		int c, size_t n)
{
	size_t			i;
	unsigned char	*strt;
	unsigned char	*end;
	void			*nptr;

	nptr = NULL;
	strt = (unsigned char*)src;
	end = (unsigned char*)dst;
	i = 0;
	while (i < n)
	{
		*end = *strt;
		if (*strt == (unsigned char)(c))
		{
			return (++end);
		}
		end++;
		strt++;
		i++;
	}
	return (nptr);
}
