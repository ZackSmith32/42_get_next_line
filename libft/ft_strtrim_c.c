/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 16:19:49 by zsmith            #+#    #+#             */
/*   Updated: 2016/10/06 17:53:44 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** input is a string
** take white input c off of ends
** white spaces can exist in the middle
*/

#include "libft.h"

static int		malloc_size(int start, int end)
{
	if (end < start)
		return (1);
	return (end - start + 2);
}

char			*ft_strtrim_c(char const *s, char c)
{
	int		j;
	int		i;
	int		k;
	char	*ret;

	i = 0;
	while ((s[i] == c) && (s[i] != '\0'))
		i++;
	j = ft_strlen(s) - 1;
	while ((s[j] == c) && (j >= 0))
		j--;
	ret = (char *)malloc(sizeof(char) * (malloc_size(i, j)));
	if (ret == 0)
		return (NULL);
	k = 0;
	while (i <= j)
	{
		ret[k] = s[i];
		i++;
		k++;
	}
	ret[k] = '\0';
	return (ret);
}
