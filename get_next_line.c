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

int		get_next_line(const int fd, char **line)
{
	printf("in: get_next_line\n");
	int		start_pt;
	static t_list	**hash;

	if (!(*line))
	{
		printf("line not null.  line: %s", *line);
		return (-1);
	}
	//ft_bzero(*line, 1);
	hash = (t_list **)malloc(sizeof(t_list*) * 100);
	if (!hash[fd])
		hash[fd] = ft_lstnew(0, sizeof(int));
	// printf("hash test %d\n", (int)hash[fd]->content);
	// printf("in: get_next_line: after if\n");

	start_pt = read_to_nl(fd, (int)hash[fd]->content);
	printf("start point: %d\n", start_pt);
	// hash[fd]->content = &start_pt;
	return (1);
}

/*
** read_to_nl, returns the starting index of the next line or 0 if DNE
*/

int		read_to_nl(int fd, int start_pt)
{
	printf("in: read_to_nl\n");
	char	*buf;
	char	*ret;
	int		index;
	int		counter;

	counter = 0;
	ret = "\0";
	buf = (char *)malloc(BUFF_SIZE + 1);
	while ((index = read(fd, buf, BUFF_SIZE)))
	{
		printf("start_pt: %d, counter: %d\n", start_pt, counter);
		buf[index] = '\0';
		printf("%s\n", buf);
		if (counter <= start_pt && counter + BUFF_SIZE > start_pt)
			ret = ft_strccat(ret, buf + (start_pt - counter), '\n');
		else
			ret = ft_strccat(ret, buf, '\n');
		counter += check_nl(buf, start_pt - counter);
		if (check_nl(buf, start_pt - counter) != BUFF_SIZE && counter > start_pt)
			break;
		printf("after break\n");
	}

	printf("outside while\n");
	return (start_pt + ft_strlen(ret));
}

int		check_nl(char *buf, int start_pt)
{
	int		i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n' && i >= start_pt)
			break;
		i++;
	}
	printf("check_nl i: %d\n", i);
	return (i);
}




	// 	printf("index: %d\n", index);
	// 	printf("buf: '%s'\n", buf);
	// 	printf("ret: %s\n", ret);
	// printf("out of loop ret: %s\n", ret);

























