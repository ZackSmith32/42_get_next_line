/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 23:20:16 by zsmith            #+#    #+#             */
/*   Updated: 2016/11/21 19:59:35 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include "libft/includes/libft.h"

# define BUFF_SIZE 32

typedef struct		b_list
{
	int				fd;
	void			*content;
	size_t			content_size;
	struct b_list	*next;
}					a_list;

int			get_next_line(const int fd, char **line);
int			central(int fd, a_list *holder, char **line);
int			check_struct(a_list *holder, char **line);
int			read_buf(int fd, a_list *holder, char **line);
int			set_line(a_list *holder, char **line);

#endif
