/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/10 17:34:30 by jungslee          #+#    #+#             */
/*   Updated: 2024/03/20 17:32:28 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
TODO 
1. 맵이 \n \0 이런식으로 끝나는 경우 에러가 남.
2. 맵이 유효조건을 충족하지 못하는 경우에 맵이 출력되면 안됨.
3. 에러 처리.
*/

char	*sl_strjoin(char *origin, char *new_read, int joint_len)
{
	int		i;
	int		j;
	char	*joint;

	i = 0;
	joint = (char *)malloc(sizeof(char) * (joint_len + 1));
	if (joint == NULL)
		handle_strerror("Malloc error");//TODO ERROR : 말록
	while ((origin != NULL) && (origin[i] != '\0'))
	{
		joint[i] = origin[i];
		i++;
	}
	j = 0;
	while (i < joint_len)
	{
		joint[i] = new_read[j];
		j++;
		i++;
	}
	joint[i] = '\0';
	if (origin != NULL)
		free(origin);
	return (joint);
}


void	fill_map_input(t_map *map, char *buf)
{
	int	i;
	int	j;
	int	idx;

	i = 0;
	j = 0;
	idx = 0;
	map->input = (char **)malloc(sizeof(char *) * map->height);
	if (map->input == NULL)
		handle_strerror("Malloc error");// TODO  ERROR : 말록에러
	while (i < map->height)
	{
		map->input[i] = (char *)malloc(sizeof(char) * map->width);
		if (map->input[i] == NULL)
			handle_strerror("Malloc error");// TODO ERROR : 말록에러인데! 말록된 위의 행들도 모두 프리해줘야하는 그런.
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

void	get_map_size(t_map *map, char *buf)
{//TODO 함수 줄 줄이기 -> 조건을 간단히 하기.
	int	idx;
	int	wid_tmp;

	idx = 0;
	wid_tmp = 0;
	while (buf[idx] == '\n')
		idx++;
	while (buf[idx] != '\0')
	{
		wid_tmp++;
		if (buf[idx + 1] == '\n' || buf[idx + 1] == '\0')
		{
			if ((buf[idx] != '\n' && \
			(buf[idx + 1] == '\n' || buf[idx + 1] == '\0')))
				map->height++;
			if (buf[idx] == '\n' && (buf[idx + 1] == '\0' || buf[idx + 1] == '\n'))
			{
				idx++;
				continue ;
			}
			if (map->width != 0 && map->width != wid_tmp)
				handle_strerror("Wrong map input : Not a rectangle"); //TODO ERROR : 직사각형이 아님.
			map->width = wid_tmp;
			wid_tmp = 0;
			if (buf[idx + 1] == '\n')
				idx++;
		}
		idx++;
	}
}


char	*read_map(int fd, t_map *map)
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
			handle_strerror("Read error");
		if (read_len == 0)
			break;
		joint_len += read_len;
		join_buf = sl_strjoin(join_buf, read_buf, joint_len);
		if (join_buf == NULL)
			handle_strerror("Malloc error");//말록 에러
	}
	return (join_buf);
}

void	read_and_init_map(void *mlx, t_map *map, int fd)
{
	char	*buf;
	
	map->height = 0;
	map->width = 0;
	buf = read_map(fd, map);
	get_map_size(map, buf);
	fill_map_input(map, buf);
	map->mlx_win = mlx_new_window(mlx, 64 * map->width, 64 * map->height, WIN_NAME);//mlx함수에 대한 에러처리도 필요할가??
	free(buf);
}
