/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 17:32:06 by zsmith            #+#    #+#             */
/*   Updated: 2016/09/27 00:24:34 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	while (j <= i)
	{
		if (*s == (char)c)
			return ((char*)s);
		s++;
		j++;
	}
	return (NULL);
}
