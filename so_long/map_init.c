/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:34:30 by jungslee          #+#    #+#             */
/*   Updated: 2024/03/10 17:47:00 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*sl_strjoin(char *origin, t_buf unit, int joint_len)
{
	int		i;
	int		j;
	char	*joint;

	i = 0;
	joint = (char *)malloc(sizeof(char) * (joint_len + 1));
	if (joint == NULL)
		return (0);//TODO ERROR : 말록
	while ((origin != NULL) && (*(origin + i) != '\0'))
	{
		*(joint + i) = *(origin + i);
		i++;
	}
	j = 0;
	while (i < joint_len)
	{
		*(joint + i) = *(unit.buf + j);
		j++;
		i++;
	}
	*(joint + i) = '\0';
	free(origin);
	return (joint);
}

int	fill_map_input(t_map *map, char *buf, int hei, int wid)
{
	int	i;
	int	j;
	int	idx;

	i = 0;
	j = 0;
	idx = 0;
	map->input = (char **)malloc(sizeof(char *) * hei);
	if (map->input == NULL)
		return (0);// TODO  ERROR : 말록에러
	while (i < hei)
	{
		map->input[i] = (char *)malloc(sizeof(char) * wid);
		if (map->input[i] == NULL)
			return (0);// TODO ERROR : 말록에러인데! 말록된 위의 행들도 모두 프리해줘야하는 그런.
		j = 0;
		while (j < wid)
		{
			map->input[i][j] = *(buf + idx++);
			j++;
		}
		i++;
		idx++;
	}
	return (1);
}

int	get_map_size(t_map *map, char *buf)
{
	int	idx;
	int	wid_tmp;

	idx = 0;
	wid_tmp = 0;
	while (*(buf + idx) == '\n')
		idx++;
	while (*(buf + idx) != '\0')
	{
		wid_tmp++;
		if (*(buf + idx + 1) == '\n' || *(buf + idx + 1) == '\0')
		{
			if ((*(buf + idx) != '\n' && *(buf + idx + 1) == '\n') \
			|| (*(buf + idx) != '\n' && *(buf + idx + 1) == '\0'))
				map->height++;//TODO 이거 마지막에 \n \0인 경우에 조건을 어떻게 걸러야하낟..?
			if (map->width != 0 && map->width != wid_tmp)
				return (0); //TODO ERROR : 직사각형이 아님.
			map->width = wid_tmp;
			wid_tmp = 0;
			if (*(buf + idx + 1) == '\n')
				idx++;
		}
		idx++;
	}
	return (1);
}

int	read_and_init_map(void *mlx, t_map *map, int fd)
{
	t_buf	unit;
	char	*join_buf;
	int		joint_len;

	joint_len = 0;
	map->height = 0;
	map->width = 0;
	while (1)
	{
		unit.read_len = read(fd, unit.buf, BUFFER_SIZE);
		if (unit.read_len == -1)
			return (0);//read에러
		if (unit.read_len == 0)
			break;
		joint_len += unit.read_len;
		join_buf = sl_strjoin(join_buf, unit, joint_len);
		if (join_buf == NULL)
			return (0);//말록 에러
	}
	get_map_size(map, join_buf);
	if (fill_map_input(map, join_buf, map->height, map->width) == 0)
		return (0);//여기도 말록에러
	map->mlx_win = mlx_new_window(mlx, 64 * map->width, 64 * map->height, WIN_NAME);//mlx함수에 대한 에러처리도 필요할가??
	return (1);
}
