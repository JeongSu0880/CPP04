/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:34:01 by jungslee          #+#    #+#             */
/*   Updated: 2024/03/28 21:55:10 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_enemy(t_param *param)
{
	t_coordinate	now;
	int				idx;
	t_enemy			*enemy;

	now.i = 0;
	idx = 0;
	param->elem.enemies = (t_enemy *)malloc(sizeof(t_enemy) \
							* param->elem.enemy_cnt);
	if (param->elem.enemies == 0)
		handle_str_error("Malloc error!");
	enemy = param->elem.enemies;
	while (now.i < param->map.height)
	{
		now.j = 0;
		while (now.j < param->map.width)
		{
			if (param->map.input[now.i][now.j] == 'B')
			{
				enemy[idx].now = now;
				idx++;
			}
			(now.j)++;
		}
		(now.i)++;
	}
}

int	check_if_fail(t_param *param, t_coordinate coor)
{
	int	idx;

	idx = 0;
	while (idx < param->elem.enemy_cnt)
	{
		if (coor.i == param->elem.enemies[idx].now.i && \
			coor.j == param->elem.enemies[idx].now.j)
		{
			swap_locat(param, coor);
			print_map(param);
			print_enemy(param);
			print_img(param, "./textures/monkey.xpm", \
						param->elem.player.i, param->elem.player.j);
			param->game_end = 1;
			return (1);
		}
		idx++;
	}
	return (0);
}

static int	get_direction(t_param *param, int rand_num, \
					t_coordinate now, t_coordinate *direct)
{
	(*direct).i = 0;
	(*direct).j = 0;
	if (rand_num % 4 == 0)
		(*direct).i = -1;
	else if (rand_num % 4 == 1)
		(*direct).j = 1;
	else if (rand_num % 4 == 2)
		(*direct).i = 1;
	else if (rand_num % 4 == 3)
		(*direct).j = -1;
	if (!((param->map.input[now.i + (*direct).i][now.j + (*direct).j] == '0' || \
		param->map.input[now.i + (*direct).i][now.j + (*direct).j] == 'P') && \
		param->map.input[now.i + (*direct).i][now.j + (*direct).j] != 'B'))
		return (0);
	return (1);
}

static void	random_move(t_param *param)
{
	int				to_rand;
	t_coordinate	direct;
	int				idx;
	int				offset;
	t_coordinate	now;

	idx = 0;
	offset = 0;
	while (idx < param->elem.enemy_cnt)
	{
		to_rand = param->move + idx + offset;
		now = param->elem.enemies[idx].now;
		if (get_direction(param, to_rand, now, &direct) == 0)
		{
			offset++;
			continue ;
		}
		param->map.input[now.i][now.j] = '0';
		print_img(param, "./textures/sand.xpm", now.i, now.j);
		param->elem.enemies[idx].now.i += direct.i;
		param->elem.enemies[idx].now.j += direct.j;
		param->map.input[now.i + direct.i][now.j + direct.j] = 'B';
		offset = 0;
		idx++;
	}
}

int	move_enemy(t_param *param)
{
	t_enemy			*enemy;

	if (param->game_end == 1)
		return (0);
	enemy = param->elem.enemies;
	(param->frame)++;
	if (param->frame % 5000 == 0)
	{
		random_move(param);
		if (check_if_fail(param, param->elem.player) == 1)
		{
			handle_fail(param->mlx, &(param->map));
			return (0);
		}
		param->frame = 0;
		move_player(param);
		print_enemy(param);
	}
	return (1);
}
