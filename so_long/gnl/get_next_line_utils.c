/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:59:14 by jungslee          #+#    #+#             */
/*   Updated: 2024/02/26 20:57:20 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fd	*init_node(int fd, t_fd *front, t_fd *back)
{
	t_fd	*node;

	node = (t_fd *)malloc(sizeof(t_fd));
	if (node == NULL)
		return (0);
	node->fd = fd;
	node->front = front;
	node->back = back;
	node->rest = NULL;
	return (node);
}

int	free_and_init(char **allocated, char *new, int return_vl)
{
	if (*allocated != NULL)
		free(*allocated);
	*allocated = new;
	return (return_vl);
}

int	gnl_strlen(char *str)
{
	int	cnt;

	if (str == NULL || *str == '\0')
		return (0);
	cnt = 0;
	while (str[cnt])
		cnt++;
	return (cnt);
}

int	gnl_sub_str(char **dest, char *str, int start, int end)
{
	char	*dest_tmp;
	int		dest_len;
	int		i;
	int		j;

	i = -1;
	j = 0;
	dest_tmp = NULL;
	dest_len = 0;
	if (str == NULL)
		return (0);
	if (*dest != str)
		dest_len = gnl_strlen(*dest);
	dest_tmp = (char *)malloc(sizeof(char) * (end - start + 2 + dest_len));
	if (dest_tmp == NULL)
		return (-1);
	while ((++i < dest_len) && (dest_len != 0) && (*dest != str))
		*(dest_tmp + i) = *(*dest + i);
	while (i < (dest_len + end - start + 1))
		*(dest_tmp + i++) = *(str + start + j++);
	*(dest_tmp + i) = '\0';
	free_and_init(dest, dest_tmp, 0);
	return (i);
}

int	check_buf(t_fd **fd_list, t_fd **now_fd, char **ret, t_buf unit)
{
	int	temp;

	if (unit.read_len != 0)
	{
		if (gnl_sub_str(&((*now_fd)->rest), unit.buf, 0, unit.read_len - 1) < 0)
		{
			del_file(now_fd, fd_list, ret);
			return (0);
		}
	}
	temp = find_new_line((*now_fd)->rest, gnl_strlen((*now_fd)->rest) - 1, \
						ret, *now_fd);
	if (temp == 0)
	{
		del_file(now_fd, fd_list, ret);
		return (0);
	}
	else if (temp == 1)
		return (1);
	return (2);
}
