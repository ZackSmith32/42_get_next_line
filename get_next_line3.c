/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 16:01:14 by zsmith            #+#    #+#             */
/*   Updated: 2017/02/19 16:32:47 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>	

static int		check_struct(t_gnl *temp, char **line)
{
	int		i;
	int		str_len;
	char	*str;

	i = 0;
	if (!(temp->content))
		return (0);
	while (temp->content[i] != '\n' && temp->content[i] != '\0')
		i++;
	free(*line);
	*line = (char *)ft_memalloc(i + 1);
	ft_memcpy(*line, temp->content, (size_t)i);
	if (temp->content[i] == 0)
	{
		free(temp->content);
		temp->content = NULL;
		return (0);
	}
	str_len = ft_strlen(temp->content) - i;
	str = ft_memalloc(str_len);
	ft_memcpy(str, temp->content + (i + 1), (size_t)str_len);
	free(temp->content);
	temp->content = str;
	return (1);
}

static int	 	reading(int fd, char **line, char *buff)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while ((i = read(fd, buff, BUFF_SIZE)))
	{
		j = 0;
		if (i == -1)
			return (-1);
		buff[i] = '\0';
		while (buff[j] != '\n' && buff[j] != '\0')
			j++;
		temp = ft_strccat(*line, buff, '\n');
		free(*line);
		(*line) = temp;
		if (j != BUFF_SIZE)
			break ;
	}
	return(i);
}

static int		read_buf(int fd, t_gnl *item, char **line)
{
	char	*buff;
	int		i;
	int		j;

	j = 0;
	buff = (char *)ft_memalloc(BUFF_SIZE + 1);
	i = reading(fd, line, buff);
	while (buff[j] != '\0' && buff[j] != '\n')
		j++;
	free(item->content);
	item->content = ft_strdup(buff + (j + 1));
	free(buff);
	if (i != BUFF_SIZE)
		return (0);
	return (1);
}

static int		central(t_gnl *temp, char **line, t_gnl **head)
{
	printf("in central test->fd = %d\n", temp->fd);
	t_gnl	*h;
	t_gnl	*g;

	if (check_struct(temp, line))
		return (1);
	printf("after check_struct\n");
	if (read_buf(temp->fd, temp, line))
		return (1);
	if (ft_strlen(*line) != 0)
		return (1);
	printf("after all the work\n");
	h = (*head);
	printf("head->fd = %d\n", h->fd);
	while (h->next != 0)
	{
		g = h->next;
		printf("g->fd = %d\n", g->fd);
		if (g->fd == temp->fd)
		{
			h->next = g->next;
			free(h->content);
			free(h);
			// return (0);
		}
	}
	printf("head-fd = %d\n", (*head)->fd);
	printf("head->next = %p\n", (*head)->next);
	// free((*head)->content);
	// free(*head);
	return (0);
}

/*
 *	unfreed mallocs are from the linked list
 */
int				get_next_line(const int fd, char **line)
{
	printf("fd = %d\n", fd);
	static t_gnl	*head;
	t_gnl			*temp;

	if (fd < 0 || line == 0)
		return (-1);
	*line = (char *)ft_memalloc(1);
	if (head == NULL)
	{
		head = (t_gnl *)ft_memalloc(sizeof(t_gnl));
		head->fd = fd;
	}
	temp = head;
	while (temp->fd != fd)
	{
		if (temp->next == NULL)
		{
			printf("temp allocated\n");	
			temp->next = (t_gnl *)ft_memalloc(sizeof(t_gnl));
			temp = temp->next;
			temp->fd = fd;
			break ;
		}
		temp = temp->next;
	}
	return (central(temp, line, &head));
}


















