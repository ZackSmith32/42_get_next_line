/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 13:12:28 by zsmith            #+#    #+#             */
/*   Updated: 2016/10/05 15:51:24 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strdup(const char *src)
{
	int		i;
	char	*str;
	void	*nullptr;

	nullptr = NULL;
	i = 0;
	if (!(src))
		return (0);
	while (src[i])
		i++;
	str = (char*)malloc(sizeof(char) * (i + 1));
	if (str == 0)
		return (nullptr);
	i = 0;
	while (src[i])
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
