/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 17:01:29 by zsmith            #+#    #+#             */
/*   Updated: 2016/10/03 19:09:10 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** concats src to the end of dest
** total return does not exceed size chars
** garuntees \0 termination
** UNLESS!! size of dest >= size
** this is described in the man as "as long as there is one bite free in dest"
*/

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (src[k])
		k++;
	while (dst[i])
		i++;
	if (i >= size)
		return (size + k);
	while (src[j] && j + i + 1 < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + k);
}
