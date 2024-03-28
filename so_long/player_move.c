/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 17:59:12 by jungslee          #+#    #+#             */
/*   Updated: 2024/03/28 21:56:47 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	walk_direction(int keycode, t_param *param, t_coordinate *next)
{
	if (keycode == Keycode_ESC)
		exit(0);
	else if (param->game_end == 1)
		return (0);
	else if (keycode == Keycode_A)
		next->j -= 1;
	else if (keycode == Keycode_S)
		next->i += 1;
	else if (keycode == Keycode_D)
		next->j += 1;
	else if (keycode == Keycode_W)
		next->i -= 1;
	else
		return (0);
	return (1);
}

int	move_player(t_param *param)
{
	int				num;
	t_coordinate	now;
	char			*img_1;
	char			*img_2;

	display_movement(param);
	now = param->elem.player;
	num = now.i;
	if (walk_motion(param, &img_1, &img_2) == 0)
	{
		img_1 = "./textures/monkey.xpm";
		img_2 = "./textures/monkey.xpm";
	}
	if (param->keycode == Keycode_A || param->keycode == Keycode_D)
		num = now.i * param->map.width + now.j;
	else
		num = now.i;
	if (num % 2 == 0)
		print_img(param, img_1, param->elem.player.i, param->elem.player.j);
	else
		print_img(param, img_2, param->elem.player.i, param->elem.player.j);
	return (1);
}

void	swap_locat(t_param *param, t_coordinate next)
{
	param->map.input[next.i][next.j] = 'P';
	param->map.input[param->elem.player.i][param->elem.player.j] = '0';
	print_img(param, "./textures/sand.xpm", param->elem.player.i, \
									param->elem.player.j);
	print_img(param, "./textures/segal.xpm", param->elem.exit.i, \
									param->elem.exit.j);
	param->elem.player = next;
}

int	walk_motion(t_param *param, char **img_1, char **img_2)
{
	if (param->keycode == Keycode_A)
	{
		*img_1 = "./textures/left_walk_1.xpm";
		*img_2 = "./textures/left_walk_2.xpm";
	}
	else if (param->keycode == Keycode_S)
	{
		*img_1 = "./textures/down_walk_1.xpm";
		*img_2 = "./textures/down_walk_2.xpm";
	}
	else if (param->keycode == Keycode_D)
	{
		*img_1 = "./textures/right_walk_1.xpm";
		*img_2 = "./textures/right_walk_2.xpm";
	}
	else if (param->keycode == Keycode_W)
	{
		*img_1 = "./textures/up_walk_1.xpm";
		*img_2 = "./textures/up_walk_2.xpm";
	}
	else
		return (0);
	return (1);
}

void	write_movement(t_param *param)
{
	int	digit;

	param->char_move = sl_strnbr(param->move, &digit);
	write(1, "number of movement : ", 21);
	write(1, param->char_move, digit);
	write(1, "\n", 1);
}
