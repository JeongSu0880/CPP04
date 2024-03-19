/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 11:57:17 by jungslee          #+#    #+#             */
/*   Updated: 2024/03/10 18:39:13 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_new_line(char *cp_buf, int cp_end, char **ret, t_fd *now_fd)
{
	int	nl;

	nl = renew_ret(cp_buf, cp_end, ret);
	if (nl == -1)
		return (0);
	else if (nl != cp_end + 1)
	{
		if (gnl_sub_str(&(now_fd->rest), cp_buf, nl + 1, cp_end) < 0)
			return (0);
		if ((nl + 1 > cp_end) && *(now_fd->rest) == '\0')
			free_and_init(&(now_fd->rest), NULL, 0);
		return (1);
	}
	free_and_init(&(now_fd->rest), NULL, 0);
	return (2);
}

t_fd	*search_fd(t_fd **fd_list, int fd)
{
	t_fd	*new;
	t_fd	*fd_tmp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	fd_tmp = *fd_list;
	while (fd_tmp != NULL)
	{
		if ((fd_tmp->fd) == fd)
			return (fd_tmp);
		if (fd_tmp->back == NULL)
			break ;
		fd_tmp = fd_tmp->back;
	}
	new = init_node(fd, fd_tmp, NULL);
	if (new == NULL)
		return (0);
	if (*fd_list == NULL)
		*fd_list = new;
	else
		fd_tmp->back = new;
	return (new);
}

int	renew_ret(char *buf, int cp_end, char **ret)
{
	int	nl_idx;
	int	len_tmp;

	nl_idx = 0;
	while (nl_idx < cp_end + 1)
	{
		if (buf[nl_idx] == '\n')
			break ;
		nl_idx++;
	}
	if (nl_idx != cp_end + 1)
	{
		len_tmp = gnl_sub_str(ret, buf, 0, nl_idx);
		if (len_tmp < 0)
			return (-1);
		return (nl_idx);
	}
	len_tmp = gnl_sub_str(ret, buf, 0, cp_end);
	if (len_tmp < 0)
		return (-1);
	return (nl_idx);
}

char	*del_file(t_fd **cur, t_fd **head, char **str)
{
	if ((*cur)->rest != NULL)
	{
		free((*cur)->rest);
		(*cur)->rest = NULL;
	}
	if ((*cur)->front == NULL)
		*head = (*head)->back;
	if ((*cur)->front != NULL)
		((*cur)->front)->back = (*cur)->back;
	if ((*cur)->back != NULL)
		((*cur)->back)->front = (*cur)->front;
	free(*cur);
	*cur = NULL;
	if (str != NULL && *str != NULL)
		free_and_init(str, NULL, 0);
	return (0);
}

char	*get_next_line(int fd)
{
	static t_fd	*fd_list = NULL;
	t_fd		*now_fd;
	t_buf		unit;
	char		*ret;
	int			temp;

	ret = NULL;
	now_fd = search_fd(&fd_list, fd);
	if (now_fd == 0)
		return (0);
	while (1)
	{
		unit.read_len = read(fd, unit.buf, BUFFER_SIZE);
		if (unit.read_len == -1)
			return (del_file(&now_fd, &fd_list, &ret));
		temp = check_buf(&fd_list, &now_fd, &ret, unit);
		if (temp != 2)
			return (ret);
		if (unit.read_len == 0)
			break ;
	}
	if (now_fd->rest == NULL)
		del_file(&now_fd, &fd_list, NULL);
	return (ret);
}
