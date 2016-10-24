/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 23:20:10 by zsmith            #+#    #+#             */
/*   Updated: 2016/10/17 23:47:21 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	static int	index;
	char		buf[BUFF_SIZE];
	int			j

	while (1)
	{
		j = 0
		if(index = read(fd, buf, BUFF_SIZE))
		{
			while (buf[j] != '\0')
			{
				if (buf[j] == '\n')
					break;
				j++
			}
		}
		else
		{
			ft_putstr("error\n");
			return (0);
		}
	}	

}