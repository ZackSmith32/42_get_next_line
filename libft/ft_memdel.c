/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 14:47:44 by zsmith            #+#    #+#             */
/*   Updated: 2016/10/03 19:40:26 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** the address that used to point to *ap should now point to NULL
** free the pointer whose address is provided (*ap)
*/

#include "libft.h"

void	ft_memdel(void **ap)
{
	if (!ap)
		return ;
	free(*ap);
	*ap = NULL;
}
