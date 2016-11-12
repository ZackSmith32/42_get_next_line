/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 11:57:06 by zsmith            #+#    #+#             */
/*   Updated: 2016/10/03 19:45:21 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this funciton modifies each element of a string with a passed funtion pointer
** the funtion pointer also takes the index of the element it is modifying
*/

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (*s)
	{
		f(i, s);
		i++;
		s++;
	}
}
