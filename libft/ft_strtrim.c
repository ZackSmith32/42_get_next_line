/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 16:19:49 by zsmith            #+#    #+#             */
/*   Updated: 2016/10/06 17:51:31 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** input is a string
** take white spaces off of ends
** white spaces can exist in the middle
*/

#include "includes/libft.h"

static int		malloc_size(int start, int end)
{
	if (end < start)
		return (1);
	return (end - start + 2);
}

char			*ft_strtrim(char const *s)
{
	int		j;
	int		i;
	int		k;
	char	*ret;

	i = 0;
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && (s[i] != '\0'))
		i++;
	j = ft_strlen(s) - 1;
	while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && (j >= 0))
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
