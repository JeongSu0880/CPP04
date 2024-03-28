/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:34:30 by jungslee          #+#    #+#             */
/*   Updated: 2024/03/28 21:17:12 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	fill_map_input(t_map *map, char *buf)
{
	int	i;
	int	j;
	int	idx;

	i = 0;
	j = 0;
	idx = 0;
	map->input = (char **)malloc(sizeof(char *) * map->height);
	if (map->input == NULL)
		handle_str_error("Malloc error");
	while (i < map->height)
	{
		map->input[i] = (char *)malloc(sizeof(char) * map->width);
		if (map->input[i] == NULL)
			handle_str_error("Malloc error");
		j = 0;
		while (j < map->width)
		{
			map->input[i][j] = buf[idx++];
			j++;
		}
		i++;
		idx++;
	}
}

static void	get_height_and_width(t_map *map, char *buf, int idx, int *wid_tmp)
{
	while (buf[idx] != '\0')
	{
		(*wid_tmp)++;
		if (buf[idx + 1] == '\n' || buf[idx + 1] == '\0')
		{
			if ((buf[idx] != '\n' && (buf[idx + 1] == '\n' || \
				buf[idx + 1] == '\0')))
				map->height++;
			if (buf[idx] == '\n' && (buf[idx + 1] == '\0' || \
				buf[idx + 1] == '\n'))
			{
				idx++;
				continue ;
			}
			if (map->width != 0 && map->width != *wid_tmp)
				handle_str_error("Wrong map input : Not a rectangle");
			map->width = *wid_tmp;
			*wid_tmp = 0;
			if (buf[idx + 1] == '\n')
				idx++;
		}
		idx++;
	}
}

static void	get_map_size(t_map *map, char *buf)
{
	int	idx;
	int	wid_tmp;

	idx = 0;
	wid_tmp = 0;
	while (buf[idx] == '\n')
		idx++;
	get_height_and_width(map, buf, idx, &wid_tmp);
}

static char	*read_map(int fd)
{
	char	read_buf[BUFFER_SIZE];
	int		read_len;
	int		joint_len;
	char	*join_buf;

	joint_len = 0;
	read_len = 0;
	join_buf = NULL;
	while (1)
	{
		read_len = read(fd, read_buf, BUFFER_SIZE);
		if (read_len == -1)
			handle_str_error("Read error");
		if (read_len == 0)
			break ;
		joint_len += read_len;
		join_buf = sl_strjoin(join_buf, read_buf, joint_len);
		if (join_buf == NULL)
			handle_str_error("Malloc error");
	}
	if (joint_len == 0)
		handle_str_error("No input!");
	return (join_buf);
}

void	read_and_init_map(void *mlx, t_map *map, int fd)
{
	char	*buf;

	map->height = 0;
	map->width = 0;
	buf = read_map(fd);
	get_map_size(map, buf);
	fill_map_input(map, buf);
	map->mlx_win = mlx_new_window(mlx, 64 * map->width, \
		64 * map->height, WIN_NAME);
	free(buf);
}
