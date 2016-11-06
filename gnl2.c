#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#define BUFFSIZE 32
static t_list	info[200];

int		central(int fd, t_list *holder, char **line);
int		leftovers(t_list *holder, char **line);
int		read_buf(int fd, t_list *holder, char **line);
char	*itter(char *input, int index, t_list *holder);

// maybe put ft_swap in library

// I think leftovers needs to return a string for use in read.


int		gnl(int fd, char **line)
{
	t_list			*holder;

	holder = &(info[fd]);
	if(central(fd, holder, line))
	{
		return (1);
	}
	return (0);
}

int		central(int fd, t_list *holder, char **line)
{
	if (leftovers(holder, line))
		return (1);
	if (read_buf(fd, holder, line))
		return (1);
	if (leftovers(holder, line))
		return (1);
	return (0);
}

int		leftovers(t_list *holder, char **line)
{
	int		i;
	int		index;
	char	*input;

	i = 0;
	index = (int)holder->content_size + 1;
	input = (char*)holder->content;	
	// check if this is the first iteration
	// if so nothing has been read yet
	if (!(input))
		return (0);
	// check if the index is at the end of the string
	// prior to looking at the string at all.
	// this would indicate that the previous itteration returned
	// the last line and we should stop reading.
	// This conditional will be useful when leftovers is called after read
	if (ft_strlen(input) == index)
		return (0);
	// checks for multiple newlines in a row
	if (input[index] == '\n')
	{
		(holder->content_size)++;
		*line = ft_strdup("\0");
		return (0);
	}
	*line = itter(input, index, holder);
	if (index == ft_strlen(input))
		return (1);
	return (0);
}

char	*itter(char *input, int index, t_list *holder)
{
	int		i;
	char	*str;

	i = 0;
	while (input[index + i] != '\n' && input[index] != '\0')
		i++;
	str = (char *)malloc(i + 1); 
	while (input[index + i] != '\0' && input[index + i] != '\n' && *input)
	{
		str[i] = input[index + i];
		i++;
	}
	str[i] = '\0';
	holder->content_size = i + index;
	return (str);
}

int		read_buf(int fd, t_list *holder, char **line)
{
	int		i;
	char	*buf;
	char	*temp;

	i = 0;
	buf = (char *)malloc(sizeof(char) * (BUFFSIZE + 1));
	while ((i = read(fd, buf, BUFFSIZE)))
	{
		if (i = -1)
			return (0);
		buf[i] = '\0';
		temp = ft_strdup(*line);
		free(*line);
		*line = (char *)malloc(ft_strlen(temp) + i)
		ft_strcpy(*line, temp);
		ft_strcat(*line, leftovers(buf, 0, ));
	}
}











	// printf("gnl: content = %s\n", (char *)(holder->content));
	// printf("gnl: content_size = %d\n", (int)(holder->content_size));