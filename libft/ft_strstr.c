/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 18:10:42 by zsmith            #+#    #+#             */
/*   Updated: 2016/09/27 16:07:27 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		j;
	char	*lit;
	char	*bg;

	bg = (char*)big;
	lit = (char*)little;
	if (!(*lit))
		return ((char *)bg);
	while (*bg != '\0')
	{
		j = 0;
		while (lit[j] == bg[j])
		{
			if (lit[j + 1] == '\0')
			{
				return ((char *)(bg));
			}
			j++;
		}
		bg++;
	}
	return (NULL);
}
