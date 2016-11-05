#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#define BUFFSIZE 32
static t_list	info;

char	*leftovers(char *input, int index, t_list *holder);
int		loop_through(int fd, t_list *holder, char **line);

int		gnl(int fd, char **line)
{
	printf("in gnl\n");
	int				j;
	t_list			*holder;

	j = 0;
	holder = &info;
	// holder = (t_list *)malloc(sizeof(t_list));
	// holder = ft_lstnew("/0", 0);
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
	printf("outside leftovers.  line = %s\n", *line);
	printf("ft_strlen(holder->content) = %d\n", (int)(ft_strlen(holder->content)));
	printf("holder->content_size = %d\n", (int)(holder->content_size));
	if ((int)(holder->content_size) != BUFFSIZE 
		&& 
		(int)(ft_strlen(holder->content)) > (int)(holder->content_size))
	{
		printf("in loop_through if\n");
		return (1);
	}
	printf("after loop_trough if\n");
	while ((j = read(fd, buf, BUFFSIZE)))
	{
		buf[j] = '\0';
		str_holder = ft_strdup(*line);
		free(*line);
		*line = (char *)malloc(ft_strlen(str_holder) + BUFFSIZE + 1); //needs to be updated BUFFSIZE not right
		printf("here\n");	
		ft_strcpy(*line, str_holder);
		*line = ft_strcat(*line, leftovers(buf, 0, holder));
		if (holder->content_size != BUFFSIZE)
			break;
		printf("______________\n");
	}
	printf("out of loop\n");
	// printf("line: %s\n", line);
	printf("content = %s\n", holder->content);
	printf("content_size = %d\n", (int)(holder->content_size));
	if (j == 0)
	{
		printf("here1\n");
		return (0);
	}
	else
	{
		printf("here2\n");
		return (1);
	}
}

char	*leftovers(char *input, int index, t_list *holder)
{	
	printf(">>>> in leftovers\ninput: %s\n", input);
	int		i;
	int		j;
	char	*str;
	i = 0;
	j = 0;
	if (!(input))
	{
		printf("input = NULL\n");
		return (0);
	}
	printf("after if\n");
	while (	input[index + i] != '\0'
			&&
			input[index + i] != '\n')
		i++;
	printf("i = %d\n", i);
	str = (char *)malloc(i + 1);
	i = 0;
	while (	input[index + i] != '\0'
			&&
			input[index + i] != '\n'
			&&
			*input)
	{
		printf("str[i] = %c, i = %d \n", input[index + i], i);
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
	printf("leftovers: content = %s\n", (char *)(holder->content));
	printf("leftovers: content_size = %d\n", (int)(holder->content_size));
	printf("leftovers: str = %s\n", str);
	printf(">>>> out leftovers\n");
	return (str);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	**line;
	int		i;

	i = 0;

	line = (char **)malloc(sizeof(char *) * 1);
	fd = open(argv[1], O_RDONLY);
	while (gnl(fd, line))
	{
		printf("result: %s\n", *line);
		printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	}
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