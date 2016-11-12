/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_c.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/20 13:12:28 by zsmith            #+#    #+#             */
/*   Updated: 2016/10/05 13:31:34 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Duplicates the provided string, untill a delimiter c is reached
**	delimiter c is provided to the function
*/

#include "libft.h"

char	*ft_strdup_c(const char *src, char c)
{
	int		i;
	char	*str;
	void	*nullptr;

	nullptr = NULL;
	i = 0;
	while (src[i] != c && src[i] != '\0')
		i++;
	str = (char*)malloc(sizeof(char) * (i + 1));
	if (str == 0)
		return (nullptr);
	i = 0;
	while (src[i] != c && src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
