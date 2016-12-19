/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mba <mba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:01:14 by zsmith            #+#    #+#             */
/*   Updated: 2016/12/19 15:21:38 by mba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		set_line(t_a_list *holder, char **line)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = ft_strlen(*line);
	temp = ft_strdup(*line);
	free(*line);
	while (((char *)(holder->content))[holder->content_size + i] != '\0'
				&&
				((char *)holder->content)[holder->content_size + i] != '\n')
		i++;
	*line = (char *)malloc(ft_strlen(temp) + i + 1);
	ft_strcpy(*line, temp);
	free(temp);
	i = 0;
	while (((char *)holder->content)[holder->content_size + i] != '\0' &&
				((char *)holder->content)[holder->content_size + i] != '\n')
	{
		line[0][j + i] = ((char *)holder->content)[holder->content_size + i];
		i++;
	}
	line[0][(j + i)] = '\0';
	holder->content_size = holder->content_size + i;
	return (1);
}

int		read_buf(int fd, t_a_list *holder, char **line)
{
	int		i;
	char	*buf;

	i = 0;
	buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	while ((i = read(fd, buf, BUFF_SIZE)))
	{
		if (i == -1)
			return (-1);
		buf[i] = '\0';
		holder->content = buf;
		holder->content_size = 0;
		set_line(holder, line);
		if (holder->content_size != BUFF_SIZE)
			break ;
	}
	// free(buf);
	if (i == 0)
		return (0);
	return (1);
}

int		check_struct(t_a_list *holder, char **line)
{
	int		i;
	int		index;
	char	*input;

	i = 0;
	index = (int)holder->content_size;
	input = (char*)holder->content;
	if (!(input))
		return (1);
	if (index >= (int)ft_strlen(input))
		return (1);
	if (input != 0)
		holder->content_size += 1;
	set_line(holder, line);
	if (holder->content_size != ft_strlen(holder->content))
		return (0);
	return (1);
}

int		central(int fd, t_a_list *holder, char **line)
{
	int		k;

	*line = (char *)ft_memalloc(1);
	if (!(check_struct(holder, line)))
		return (1);
	k = read_buf(fd, holder, line);
	if (k == 0 && ft_strlen(*line) != 0)
		k = 1;
	return (k);
}

int		get_next_line(const int fd, char **line)
{
	static t_a_list				*holder;
	t_a_list					*temp;
	t_a_list					*temp2;
	int							z;

	if (fd < 0 || line == 0)
		return (-1);
	if (holder == NULL)
		holder = (t_a_list *)ft_memalloc(sizeof(t_a_list));
	temp = holder;
	while (temp->fd != fd)
	{
		if (temp->next == NULL)
		{
			temp2 = (t_a_list *)ft_memalloc(sizeof(t_a_list));
			temp2->fd = fd;
			temp->next = temp2;
			temp = temp->next;
			break ;
		}
		temp = temp->next;
	}
	z = central(fd, temp, line);
	return (z == 0 ? ft_free_struct(&holder) : z);
}
