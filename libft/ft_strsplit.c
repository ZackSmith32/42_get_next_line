/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 16:37:40 by zsmith            #+#    #+#             */
/*   Updated: 2016/10/05 13:33:18 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** input: string and delimiter
** split string on delimiter
** return tab of substrings
*/

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		w;
	int		i;
	char	**ans;

	if (!s)
		return (NULL);
	w = ft_word_count(s, c);
	ans = (char **)malloc(sizeof(char *) * (w + 1));
	if (ans == 0)
		return (NULL);
	i = 0;
	while (*s != '\0')
	{
		if (((i == 0 && *s != c) || (s[-1] == c && *s != c)) && (*s != '\0'))
		{
			ans[i] = ft_strdup_c(s, c);
			i++;
		}
		s++;
	}
	ans[w] = 0;
	if (w == 0)
		ans[0] = NULL;
	return (ans);
}
