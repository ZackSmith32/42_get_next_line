/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 21:00:40 by zsmith            #+#    #+#             */
/*   Updated: 2016/10/06 17:53:50 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** convert and integer into a char string
*/

#include "libft.h"

char			*ft_itoa(int nbr)
{
	char	*ans;
	int		i;
	long	n;

	n = nbr;
	i = ft_numlen(n);
	if (n < 0)
		n = n * -1;
	ans = (char *)malloc(sizeof(char) * (i + 1));
	if (ans == 0)
		return (NULL);
	ans[i] = '\0';
	if (n == 0)
		ans[--i] = 48;
	while (n != 0)
	{
		ans[--i] = n % 10 + 48;
		n = n / 10;
	}
	if (i != 0)
		ans[0] = '-';
	return (ans);
}
