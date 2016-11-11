#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#define BUFFSIZE 32
static t_list	info[200];

int		central(int fd, t_list *holder, char **line);
int		check_struct(t_list *holder, char **line);
int		read_buf(int fd, t_list *holder, char **line);
int		set_line(t_list *holder, char **line);

int		gnl(int fd, char **line)
{
	// printf("in: gnl\n");
	t_list			*holder;

	*line = (char *)malloc(1);
	line[0][0] = '\0';
	// printf("*line = %p\n", *line);
	holder = &(info[fd]);
	return(central(fd, holder, line));
	
}

int		central(int fd, t_list *holder, char **line)
{
	// printf("in: central\n");
	int		k;

	if (!(check_struct(holder, line)))
		return (1);
	k = read_buf(fd, holder, line);
	// printf("k = %d\n",  k);
	// printf("len *line: %zu\n", ft_strlen(*line));
	if (k == 0 && ft_strlen(*line) != 0)
		k = 1;
	// printf("out: central\n");
	return (k);
}

int		check_struct(t_list *holder, char **line)
{
	// printf("in: check_struct\n");
	int		i;
	int		index;
	char	*input;

	i = 0;
	index = (int)holder->content_size;
	input = (char*)holder->content;	
	// printf("after declarationes\n");
	if (!(input))
	{
		// printf("no holder->content, continue to read_buf\n");
		return (1);
	}
	// printf("after first if\n");
	if (index >= ft_strlen(input))
	{
		// printf("index greater than len therefore read all of content\n");
		return (1);
	}
	// printf("after second if\n");
	if (input != 0)
		holder->content_size += 1;
	set_line(holder, line);

	// printf("out: check_struct\n");
	if (holder->content_size != ft_strlen(holder->content))
		return (0);
	return (1);
}

int		read_buf(int fd, t_list *holder, char **line)
{
	// printf("in: read_buf\n");
	int		i;
	char	*buf;
	char	*temp;

	i = 0;
	buf = (char *)malloc(sizeof(char) * (BUFFSIZE + 1));
	while ((i = read(fd, buf, BUFFSIZE)))
	{
		// printf("in: read_buf while\n");
		if (i == -1)
			return (-1);
		buf[i] = '\0';
		// printf("before declarations\n");
		holder->content = buf;
		holder->content_size = 0;
		// printf("holder->content: %s\n", (char *)holder->content);
		// printf("holder->content_size: %d\n", (int)holder->content_size);
		set_line(holder, line);
		// printf("read: after set line\n");
		if (holder->content_size != BUFFSIZE)
			break;
		// printf("next itteration of read while loop\n");
	}
	// printf("out: read_buf\n");
	if (i == 0)
		return (0);
	return (1);
}

int		set_line(t_list *holder, char **line)
{
	// printf(">>>> in: set_line\n");
	// printf(">>>> holder->content : %s\n", (char *)holder->content);
	// printf(">>>> holder->content_size %d\n", (int)holder->content_size);
	// printf(">>>> line = %s\n", line[0]);

	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = ft_strlen(*line);
	temp = ft_strdup(*line);
	// printf("after temp\n");
	// printf("*line = %p\n", *line);
	// printf("**line = %c\n", **line);
	if (*line == '\0')
	{
		// printf("in line if\n");
		free(*line);
	}
	// printf("after first if\n");
	while 	(	((char *)(holder->content))[holder->content_size + i] != '\0'
				&&
				((char *)holder->content)[holder->content_size + i] != '\n'
			)
	{
		i++;				
	} 
	// printf("size of malloc %lu\n", ft_strlen(temp) + i + 1);
	*line = (char *)malloc(ft_strlen(temp) + i + 1);
	ft_strcpy(*line, temp);
	// printf("after malloc\n");
	// printf("holder->content : %s\n", (char *)holder->content);
	i = 0;
	while 	(	((char *)holder->content)[holder->content_size + i] != '\0'
				&&
				((char *)holder->content)[holder->content_size + i] != '\n'
			)
	{
		line[0][j + i] = ((char *)holder->content)[holder->content_size + i];
		i++;
	}
  	line[0][(j + i)] = '\0';
	holder->content_size = holder->content_size + i;
	// printf(">>>> line = %s\n", line[0]);
	// printf(">>>> holder->content_size = %d\n", (int)holder->content_size);
	// printf(">>>> out: set_line\n");
	return (1);
}

int		main(int argc, char **argv)
{
	int		fd;
	int		fd2;
	// int		fd3;
	char	**line;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;

	line = (char **)malloc(sizeof(char *) * 1);
	fd = open(argv[1], O_RDONLY);
	while (gnl(fd, line))
	{
		// printf("reutrn = %d\n", gnl(fd, line));
		printf("fd1: %s\n", *line);
		printf("~~~~~~~~~~~~~~~\n");

		if (i == 2)
		{
			fd2 = open(argv[2], O_RDONLY);
			while (gnl(fd2, line))
			{
				printf("fd2: %s\n", *line);
				printf("~~~~~~~~~~~~~~~\n");

		// 		// printf("k = %d\n", k);
		// 		if (k == -1)
		// 			break;
		// // 		if (j == 2)
		// // 		{
		// // 			fd3 = open(argv[3], O_RDONLY);
		// // 			while (gnl(fd3, line))
		// // 			{
		// // 				printf("fd3: %s\n", *line);
		// // 			}
		// // 		}
		// 		j++;
			}
		}
		i++;
	}
	// gnl(fd, line);
	printf("end: *line = %s\n", *line);
	// printf("~~~~~~~~~~~~~~~\n");
	return (0);
}




