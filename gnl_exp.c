#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#define BUFFSIZE 32
static t_list	info[200];

char	*leftovers(char *input, int index, t_list *holder);
int		loop_through(int fd, t_list *holder, char **line);

int		gnl(int fd, char **line)
{
	int				j;
	t_list			*holder;

	j = 0;
	holder = &(info[fd]);

	printf("gnl: content = %s\n", (char *)(holder->content));
	printf("gnl: content_size = %d\n", (int)(holder->content_size));
	if(loop_through(fd, holder, line))
	{
		return (1);
	}
	return (0);
}

int		loop_through(int fd, t_list *holder, char **line)
{
	int		j;
	char 	*buf;
	char	*str_holder;
	
	j = 0;
	buf = (char *)malloc(sizeof(char) * (BUFFSIZE + 1));
	*line = leftovers(holder->content, holder->content_size + 1, holder);
	printf("line = %s\n", *line);
	printf("loop: content = %s\n", (char *)(holder->content));
	printf("loop: content_size = %d\n", (int)(holder->content_size));

	if ((int)(ft_strlen(holder->content)) > (int)(holder->content_size))
	{
		printf("return 1\n");
		return (1);
	}
	while ((j = read(fd, buf, BUFFSIZE)))
	{	
		if (j == -1)
			return (-1);
		buf[j] = '\0';
		printf("buf: %s\n", buf);
		str_holder = ft_strdup(*line);
		free(*line);
		*line = (char *)malloc(ft_strlen(str_holder) + BUFFSIZE + 1); //needs to be updated BUFFSIZE not right
		ft_strcpy(*line, str_holder);
		*line = ft_strcat(*line, leftovers(buf, 0, holder));
		printf("loop: content = %s\n", (char *)(holder->content));
		printf("loop: content_size = %d\n", (int)(holder->content_size));
		if (holder->content_size != BUFFSIZE)
			break;
	}
	printf("line =|%s|\n", *line);
	printf("j = %d\n", j);
	printf("ft_strlen(*line) = %d\n", (int)ft_strlen(*line));
	if (j == 0 && 
		ft_strlen(holder->content) == holder->content_size
		&& ft_strlen(*line) == 0)
	{
		printf("in return 0\n");
		return (0);
	}
	else
	{
		printf("in return 1\n");
		return (1);
	}
}

char	*leftovers(char *input, int index, t_list *holder)
{	
	printf("in leftovers\n");
	int		i;
	char	*str;

	i = 0;
	if (!(input))
		return (0);
	if (input[index] == '\n')
	{
		(holder->content_size)++;
		return (ft_strdup("\0"));
	}
	while (input[index + i] != '\0' && input[index + i] != '\n')
		i++;
	str = (char *)malloc(i + 1);
	i = 0;
	while (input[index + i] != '\0' && input[index + i] != '\n' && *input)
	{
		str[i] = input[index + i];
		i++;
	}
	str[i] = '\0';
	if (i == 0)
		holder->content_size = 32;
	else
		holder->content_size = i + index;
	free(holder->content);
	holder->content = ft_strdup(input);
	printf("str = %s\n", str);
	printf("out leftovers\n");
	return (str);
}

int		main(int argc, char **argv)
{
	int		fd;
	// int		fd2;
	// int		fd3;
	char	**line;
	int		i;
	int		j;

	i = 0;
	j = 0;

	line = (char **)malloc(sizeof(char *) * 1);
	fd = open(argv[1], O_RDONLY);
	while (gnl(fd, line))
	{
		printf("%s\n", *line);
		printf("~~~~~~~~~~~~~~~\n");
		// if (i == 3)
		// {
		// 	fd2 = open(argv[2], O_RDONLY);
		// 	while (gnl(fd2, line))
		// 	{
		// 		printf("fd2: %s\n", *line);
		// 		if (j == 2)
		// 		{
		// 			fd3 = open(argv[3], O_RDONLY);
		// 			while (gnl(fd3, line))
		// 			{
		// 				printf("fd3: %s\n", *line);
		// 			}
		// 		}
		// 		j++;
		// 	}
		// }
		// i++;
	}
	printf("0 returned");
	return (0);
}


/*
 *	notes about read:
 *	read will resume reading at the file offset where it last stopped
 *	reading in that file.
 *	read returns the number of bytes read for that particular call, always
 *	<= size of read chunk
 *
 */ 














/*
while(gnl(fd, line))
	{
		printf("main loop: %d\n", i++);
		printf("%s\n", *line);
		printf("_________________\n");
	}
*/