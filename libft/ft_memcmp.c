/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 11:30:55 by zsmith            #+#    #+#             */
/*   Updated: 2016/09/25 11:57:50 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*word1;
	unsigned char	*word2;
	size_t			i;

	word1 = (unsigned char*)s1;
	word2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (*word1 != *word2)
			return (*word1 - *word2);
		i++;
		word1++;
		word2++;
	}
	return (0);
}
