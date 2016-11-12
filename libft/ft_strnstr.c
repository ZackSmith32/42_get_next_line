/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 20:06:42 by zsmith            #+#    #+#             */
/*   Updated: 2016/09/27 17:16:33 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	j;
	size_t	k;
	char	*bg;
	char	*lit;

	k = 0;
	bg = (char*)big;
	lit = (char*)little;
	if (!(*lit))
		return (bg);
	while (bg[k] != '\0' && k < len)
	{
		j = 0;
		while (lit[j] == bg[j + k] && (k + j < len))
		{
			if (lit[j + 1] == '\0')
				return (bg + k);
			j++;
		}
		if (k + j >= len)
			return (NULL);
		k++;
	}
	return (NULL);
}
