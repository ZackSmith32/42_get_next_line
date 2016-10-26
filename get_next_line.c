/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 23:20:10 by zsmith            #+#    #+#             */
/*   Updated: 2016/10/24 15:56:05 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


/*
int		get_next_line(const int fd, char **line)
{
	static int	index;
	char		buf[BUFF_SIZE];
	int			j;

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
*/

int		read_to_nl(int fd)
{
	char	*buf;
	char	*ret;
	int		index;
	int		counter;

	counter = 0;
	index = 0;
	ret = "\0";
	buf = (char *)malloc(BUFF_SIZE + 1);
	while ((index = read(fd, buf, BUFF_SIZE)))
	{
		buf[index] = '\0';
		printf("index: %d\n", index);
		printf("buf: '%s'\n", buf);
		counter += index;
		ret = ft_strccat(ret, buf, '\n');
		printf("ret: %s\n", ret);
		if (!(check_nl(buf)))
		{
			break;
			ft_bzero(buf, index);
			buf[index] = '\0';
		}
	}
	printf("out of loop ret: %s\n", ret);
	return (index);
}

int		check_nl(char *buf)
{
	int		i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			break;
		i++;
	}
	return (i);
}

































