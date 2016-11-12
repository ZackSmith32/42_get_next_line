/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 15:22:04 by zsmith            #+#    #+#             */
/*   Updated: 2016/10/01 15:42:38 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	int		i;
	char	*ret_str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	ret_str = (char *)malloc(len + 1);
	if (ret_str == 0)
		return (NULL);
	i = 0;
	while (len >= 0 && *s1)
	{
		ret_str[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		ret_str[i] = *s2;
		s2++;
		i++;
	}
	ret_str[i] = '\0';
	return (ret_str);
}
