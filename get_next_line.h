/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mba <mba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 23:20:16 by zsmith            #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/02/19 15:25:23 by zsmith           ###   ########.fr       */
=======
/*   Updated: 2016/12/19 15:01:38 by mba              ###   ########.fr       */
>>>>>>> b1cf7660896a22a08e2f3e85b073fa99e1841965
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include "libft/includes/libft.h"

# define BUFF_SIZE 32

typedef struct		s_gnl
{
	int				fd;
	char			*content;
	size_t			content_size;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);
<<<<<<< HEAD
=======
int					central(int fd, t_a_list *holder, char **line);
int					check_struct(t_a_list *holder, char **line);
int					read_buf(int fd, t_a_list *holder, char **line);
int					set_line(t_a_list *holder, char **line);
int					ft_free_struct(t_a_list **obj);
>>>>>>> b1cf7660896a22a08e2f3e85b073fa99e1841965

#endif
