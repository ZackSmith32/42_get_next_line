/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 14:46:04 by zsmith            #+#    #+#             */
/*   Updated: 2016/09/29 17:29:55 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*str;

	if (size == 0)
		return (NULL);
	str = (void*)malloc(size);
	if (str == 0)
		return (NULL);
	ft_memset(str, '\0', size);
	return (str);
}
