/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsmith <zsmith@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/17 23:20:16 by zsmith            #+#    #+#             */
/*   Updated: 2016/11/20 13:44:16 by zsmith           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include "libft/includes/libft.h"

# define BUFF_SIZE 9999

int			get_next_line(const int fd, char **line);
int			central(int fd, t_list *holder, char **line);
int			check_struct(t_list *holder, char **line);
int			read_buf(int fd, t_list *holder, char **line);
int			set_line(t_list *holder, char **line);

#endif
