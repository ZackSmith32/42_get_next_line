/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 22:20:48 by zsmith            #+#    #+#             */
/*   Updated: 2016/09/25 11:26:08 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	chr;
	int				i;

	i = 0;
	chr = (unsigned char)c;
	str = (unsigned char*)s;
	while (n--)
	{
		if (str[i] == chr)
			return (str + i);
		i++;
	}
	return (NULL);
}
