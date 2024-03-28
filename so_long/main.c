/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:44:18 by jungslee          #+#    #+#             */
/*   Updated: 2024/03/28 21:56:47 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_not_wall_or_enemy(t_map map, int i, int j)
{
	if (map.input[i][j] == '1' || map.input[i][j] == 'B')
		return (0);
	else
		return (1);
}

int	check_now(t_param *param)
{
	t_coordinate	now;
	t_coordinate	exit;

	exit = param->elem.exit;
	now = param->elem.player;
	if ((now.i == exit.i) && (now.j == exit.j))
	{
		if (param->elem.collect == 0)
		{
			handle_success(param->mlx, &(param->map), param->elem);
			return (1);
		}
		else
		{
			write(1, "need more strawberries!\n", 25);
			return (0);
		}
	}
	return (0);
}

int	check_texture(t_param *param, t_coordinate next)
{
	if (param->map.input[next.i][next.j] == '1')
		return (0);
	else if (param->map.input[next.i][next.j] == 'C')
	{
		print_img(param, "./textures/sand.xpm", next.i, next.j);
		(param->elem.collect)--;
	}
	return (1);
}

int	key_hook(int keycode, t_param *param)
{
	t_coordinate	now;
	t_coordinate	next;
	t_map			map;

	now = param->elem.player;
	map = param->map;
	next = now;
	if (walk_direction(keycode, param, &next) == 0 || \
			check_texture(param, next) == 0)
		return (0);
	if (check_if_fail(param, next) == 1)
		return (handle_fail(param->mlx, &(param->map)));
	swap_locat(param, next);
	param->move++;
	if (param->char_move != NULL)
		free(param->char_move);
	write_movement(param);
	param->keycode = keycode;
	move_player(param);
	if (check_now(param))
		param->game_end = 1;
	return (0);
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_param	param;

	if (argc != 2)
		handle_str_error("Wrong argument!");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		handle_perror();
	param.mlx = mlx_init();
	read_and_init_map(param.mlx, &(param.map), fd);
	check_map_validity(param.map, &(param.elem));
	check_enemy(&param);
	print_map(&param);
	print_enemy(&param);
	move_player(&param);
	param.move = 0;
	param.game_end = 0;
	mlx_hook(param.map.mlx_win, 2, 0, key_hook, &(param));
	mlx_hook(param.map.mlx_win, 17, 0, close_win, &(param));
	mlx_loop_hook(param.mlx, move_enemy, &(param));
	mlx_loop(param.mlx);
	close(fd);
	exit(0);
}
