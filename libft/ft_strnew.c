/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 15:00:09 by zsmith            #+#    #+#             */
/*   Updated: 2016/10/05 16:07:49 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*newnew;

	newnew = ft_memalloc(size + 1);
	if (newnew == 0)
		return (NULL);
	ft_bzero(newnew, size);
	return (newnew);
}
