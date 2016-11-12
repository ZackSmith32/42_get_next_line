/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 15:06:07 by zsmith            #+#    #+#             */
/*   Updated: 2016/10/03 19:46:59 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret_str;
	size_t	i;

	if (!s)
		return (NULL);
	ret_str = (char *)malloc(sizeof(char) * (len + 1));
	if (ret_str == 0)
		return (NULL);
	i = 0;
	while (i < len && s[i + start])
	{
		ret_str[i] = (char)s[i + start];
		i++;
	}
	ret_str[i] = '\0';
	return (ret_str);
}
