/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:57:07 by jungslee          #+#    #+#             */
/*   Updated: 2024/01/19 06:50:00 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_buf
{
	ssize_t	read_len;
	char	buf[BUFFER_SIZE];
}	t_buf;

typedef struct s_fd
{
	struct s_fd	*front;
	struct s_fd	*back;
	int			fd;
	char		*rest;
}	t_fd;

int		check_buf(t_fd **fd_list, t_fd **now_fd, char **ret, t_buf unit);
int		gnl_sub_str(char **dest, char *str, int start, int end);
int		find_new_line(char *cp_buf, int cp_end, char **ret, t_fd *now_fd);
t_fd	*init_node(int fd, t_fd *front, t_fd *back);
int		gnl_strlen(char *str);
char	*get_next_line(int fd);
char	*del_file(t_fd **fd_node, t_fd **fd_list, char **ret);
int		renew_ret(char *buf, int cp_end, char **ret);
t_fd	*search_fd(t_fd **fd_list, int fd);
int		free_and_init(char **allocated, char *new, int return_vl);

#endif