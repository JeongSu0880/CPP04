/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 11:41:31 by jungslee          #+#    #+#             */
/*   Updated: 2024/03/28 21:58:40 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_others_and_count(t_param *param)
{
	t_coordinate	now;
	char			*str;

	now.i = 0;
	now.j = 0;
	while (now.i < (param->map.height))
	{
		now.j = 0;
		while (now.j < (param->map.width))
		{
			str = classify_img(param->map.input[now.i][now.j], &now);
			if (str == 0)
				continue ;
			print_img(param, str, now.i, now.j);
			now.j++;
		}
		now.i++;
	}
	print_img(param, "./textures/segal.xpm", \
				param->elem.exit.i, param->elem.exit.j);
}

void	print_background(t_param *param)
{
	int		x;
	int		y;
	t_img	back;

	x = 0;
	y = 0;
	back.width = IMG_WIDTH;
	back.height = IMG_HEIGHT;
	back.img = mlx_xpm_file_to_image(param->mlx, "./textures/sand.xpm", \
				&(back.width), &(back.height));
	if (back.img == NULL)
		handle_str_error("No image file");
	while (y < param->map.height * IMG_HEIGHT)
	{
		while (x <= param->map.width * IMG_HEIGHT)
		{
			mlx_put_image_to_window(param->mlx, param->map.mlx_win, \
									back.img, x, y);
			x += IMG_WIDTH;
		}
		x = 0;
		y += IMG_HEIGHT;
	}
}

void	print_enemy(t_param *param)
{
	int		idx;
	t_enemy	*enemy;

	idx = 0;
	enemy = param->elem.enemies;
	while (idx < param->elem.enemy_cnt)
	{
		print_img(param, "./textures/banana.xpm", enemy[idx].now.i, \
					enemy[idx].now.j);
		idx++;
	}
}

void	print_map(t_param *param)
{
	print_background(param);
	print_others_and_count(param);
}

void	display_movement(t_param *param)
{
	int	j;

	j = 0;
	while (j < 4)
	{
		print_img(param, "./textures/sand.xpm", 0, j);
		print_img(param, "./textures/stone.xpm", 0, j);
		j++;
	}
	if (param->char_move != NULL)
	{
		mlx_string_put(param->mlx, param->map.mlx_win, \
					32, 15, 000000, "number of movement");
		mlx_string_put(param->mlx, param->map.mlx_win, \
					32, 40, 000000, param->char_move);
	}
}
