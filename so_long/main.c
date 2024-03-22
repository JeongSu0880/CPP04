#include "so_long.h" 
//TODO exit 에서의 처리... 프레임 나눠서 움직임 자연스럽게... 화면 확대 축소 가능하게, 과제의 [그래픽] 관련 처리!

void	print_img(t_param *param, char *str, int i, int j)
{
	t_img img;

	img.img = mlx_xpm_file_to_image(param->mlx, str, &(img.width), &(img.height));
	if (img.img == NULL)//TODO ERROR : 이미지 파일이 없을 경우 에러
		handle_strerror("No image file");
	mlx_put_image_to_window(param->mlx, param->map.mlx_win, img.img, j * img.width, i * img.height);
}

void	print_background(t_param *param)
{
	int	x;
	int	y;
	t_img	back;

	x = 0;
	y = 0;
	back.width = IMG_WIDTH;
	back.height = IMG_HEIGHT;
	back.img = mlx_xpm_file_to_image(param->mlx, "./xpm/sand.xpm", &(back.width), &(back.height));//TODO 이렇게 넘겨줘도 될까?
	if (back.img == NULL)
		handle_strerror("No image file");
	while (y < param->map.height * IMG_HEIGHT)
	{
		while (x <= param->map.width * IMG_HEIGHT)
		{
			mlx_put_image_to_window(param->mlx, param->map.mlx_win, back.img, x, y);
			x += IMG_WIDTH;
		}
		x = 0;
		y += IMG_HEIGHT;
	}
}

void	print_player(t_param *param)
{
	print_img(param, "./xpm/monkey.xpm", param->elem.player.i, param->elem.player.j);
}


char	*classify_img(char c, t_coordinate *now, t_param *param)
{
	if (c == '1')
		return ("./xpm/stone.xpm");
	else if (c == 'P')
		return ("./xpm/sand.xpm");
	else if (c == 'C')
		return ("./xpm/strawberry.xpm");
	else if (c == 'B')
		return ("./xpm/banana.xpm");
	else
	{
		(now->j)++;
		return (0);
	}
}

void print_others_and_count(t_param *param)
{
	t_coordinate	now;
	char	*str;

	now.i = 0;
	now.j = 0;
	print_img(param, "./xpm/segal.xpm", param->elem.exit.i, param->elem.exit.j);
	while (now.i < (param->map.height))
	{
		now.j = 0;
		while (now.j < (param->map.width))
		{
			str = classify_img(param->map.input[now.i][now.j], &now, param);
			if (str == 0)
				continue ;
			print_img(param, str, now.i, now.j);
			now.j++;
		}
		now.i++;
	}
}

void	print_map(t_param *param)
{
	print_background(param);
	print_others_and_count(param);
	// print_player(param);
}

void	test_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("hei : %d, wid : %d\n", map->height, map->width);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			printf("%c ", map->input[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int	is_not_wall_or_enemy(t_map map, int i, int j)
{
	if (map.input[i][j] == '1' || map.input[i][j] == 'B')
		return (0);
	else
		return (1);
}

void	swap_locat(t_map *map, t_elements *elem, t_coordinate next)
{
	map->input[next.i][next.j] = 'P';
	map->input[elem->player.i][elem->player.j] = '0';
	elem->player = next;
}

int check_now(t_param *param)
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

char *sl_strnbr(int num, int *digit)
{
	char	*str;
	int		num_tmp;
	int		idx;

	*digit = 0;
	num_tmp = num;
	while (num_tmp != 0)
	{
		num_tmp = num_tmp / 10;
		(*digit)++;
	}
	str = (char *)malloc(sizeof(char) * (*digit) + 1);
	idx = (*digit) - 1;
	num_tmp = num;
	str[*digit] = '\0';
	while (idx >= 0)
	{
		str[idx] = num_tmp % 10 + '0';
		num_tmp = num_tmp / 10;
		idx--;
	}
	return (str);
}

int	move_player(int keycode, t_param *param)
{
	int		cnt;
	t_coordinate now;
	t_img 	img;
	char	*img_1;
	char	*img_2;

	cnt = 0;
	while (cnt <= 64)
	{
		if (keycode == Keycode_A)
		{
			img_1 = "./xpm/left_walk_1.xpm";
			img_2 = "./xpm/left_walk_2.xpm";
			now.i = (param->elem.player.i) * img.height;
			now.j = (param->elem.player.j) * img.width - cnt;
		}
		else if (keycode == Keycode_S)
		{
			img_1 = "./xpm/down_walk_1.xpm";
			img_2 = "./xpm/down_walk_2.xpm";
			now.i = (param->elem.player.i) * img.height + cnt;
			now.j = (param->elem.player.j) * img.width;
		}
		else if (keycode == Keycode_D)
		{
			img_1 = "./xpm/right_walk_1.xpm";
			img_2 = "./xpm/right_walk_2.xpm";
			now.i = (param->elem.player.i) * img.height;
			now.j = (param->elem.player.j) * img.width + cnt;
		}
		else if (keycode == Keycode_W)
		{
			img_1 = "./xpm/up_walk_1.xpm";
			img_2 = "./xpm/up_walk_2.xpm";
			now.i = (param->elem.player.i) * img.height - cnt;
			now.j = (param->elem.player.j) * img.width;
		}
		else
			return (0);
		print_map(param);//TODO 엄청 느려진다...
		if (16 <= cnt && cnt < 48)
			img.img = mlx_xpm_file_to_image(param->mlx, img_1, &(img.width), &(img.height));
		else
			img.img = mlx_xpm_file_to_image(param->mlx, img_2, &(img.width), &(img.height));
		if (img.img == 0)
			handle_strerror("No image file");
		mlx_put_image_to_window(param->mlx, param->map.mlx_win, img.img, now.j, now.i);
		cnt += 16;
	}
	return (1);
}





int	key_hook(int keycode, t_param *param)
{
	t_coordinate	now;
	t_coordinate	next;
	t_map			map;
	char			*move;
	int				digit;

	now = param->elem.player;
	map = param->map;
	next = now;
	if (keycode == Keycode_ESC)
		exit(0);
	else if (param->game_end == 1)
		return (0);
	// else
	// {
	// 	if (move_player(keycode, param) == 0)
	// 		return (0);
	// }
	else if (keycode == Keycode_A)
		next.j -= 1;
	else if (keycode == Keycode_S)
		next.i += 1;
	else if (keycode == Keycode_D)
		next.j += 1;
	else if (keycode == Keycode_W)
		next.i -= 1;
	else
		return (0);
	if (map.input[next.i][next.j] == '1')
		return (0);
	else if (map.input[next.i][next.j] == 'C')
		param->elem.collect--;
	else if (map.input[next.i][next.j] == 'B')
	{
		swap_locat(&map, &(param->elem), next);
		print_map(param);
		handle_fail(param->mlx, &(param->map));
		param->game_end = 1;
		return (0);
	}
	param->move++;
	move = sl_strnbr(param->move, &digit);
	write(1, move, digit);
	write(1, "\n", 1);
	print_map(param);
	// print_player(param);
	move_player(keycode, param);
	swap_locat(&map, &(param->elem), next);
	// print_map(param);
	// print_other_and_count(param);
	mlx_string_put(param->mlx, param->map.mlx_win, 32, 15, 000000, "number of movement");
	mlx_string_put(param->mlx, param->map.mlx_win, 32, 40, 000000, move);
	free(move);
	if (check_now(param))
		param->game_end = 1;
	return (0);
}





int	close_win(t_param *param)
{
	exit(0);
}

// int	animation(int keycode, t_param *param)
// {
// 	print_img(param, "./smile_monkey.xpm", param->elem.player.i, param->elem.player.j);
// 	print_img(param, "./smile_monkey.xpm", param->elem.player.i, param->elem.player.j);
// 	return (0);
// }


int	main(int argc, char *argv[])
{
	int		fd;
	t_param		param;
	
	fd = open(argv[1], O_RDONLY);
	// fd = open("map.ber", O_RDONLY);
	if (fd < 0) //TODO : 해당 파일이 없을 시 에러!
		handle_perror();
	param.mlx = mlx_init();
	read_and_init_map(param.mlx, &(param.map), fd);
	check_map_validity(param.map, &(param.elem));
	print_map(&param);
	print_player(&param);
	param.move = 0;
	param.game_end = 0;
	// mlx_loop_hook(param.map.mlx_win, animation, &(param));
	mlx_hook(param.map.mlx_win, 2, 0, key_hook, &(param));
	mlx_hook(param.map.mlx_win, 17, 0, close_win, &(param));
	// mlx_loop_hook(param.map.mlx_win, )
	mlx_loop(param.mlx);
	close(fd);
	exit(0);
}
// void	sl_putnbr(int num)
// {
// 	char	c;

// 	if (num == 0)
// 		return ;
// 	sl_putnbr(num / 10);
// 	c = num % 10 + '0';
// 	write(1, &c, 1);
// }

// void	move_player(int	keycode, t_param *param, t_coordinate now, t_coordinate next)//ㄷㅏ시 고고쳐  방방향대로..
// {
// 	//void	print_img(t_param *param, char *str, int i, int j)
// 	float	i;
// 	float	j;
// 	char	*img_1;
// 	char	*img_2;
// 	int		cnt;
// 	void	*img;
// 	int		width;
// 	int		height;

// 	cnt = 1;
// 	print_img(param, "./xpm/sand.xpm", now.i, now.j);
// 	print_img(param, "./xpm/sand.xpm", next.i, next.j);
// 	if (keycode == Keycode_A)
// 	{
// 		img_1 = "./xpm/left_walk_1.xpm";
// 		img_2 = "./xpm/left_walk_2.xpm";
// 		while (cnt <= 4)
// 		{
// 			print_img(param, "./xpm/sand.xpm", now.i, now.j);
// 			print_img(param, "./xpm/sand.xpm", next.i, next.j);
// 			if (cnt % 2 == 0)
// 			{
// 				img = mlx_xpm_file_to_image(param->mlx, img_1, &(width), &(height));
// 				if (img == 0)
// 					handle_strerror("No image file");
// 				mlx_put_image_to_window(param->mlx, param->map.mlx_win, img, width * now.j - cnt * 16, now.i * height);
// 			}
// 			else
// 			{
// 				img = mlx_xpm_file_to_image(param->mlx, img_2, &(width), &(height));
// 				if (img == 0)
// 					handle_strerror("No image file");
// 				mlx_put_image_to_window(param->mlx, param->map.mlx_win, img, width * now.j - cnt * 16, now.i * height);
// 			}
// 			cnt++;
// 		}
// 	}
// 	else if (keycode == Keycode_S)
// 	{
// 		img_1 = "./xpm/down_walk_1.xpm";
// 		img_2 = "./xpm/down_walk_2.xpm";
// 		while (cnt <= 4)
// 		{
// 			print_img(param, "./xpm/sand.xpm", now.i, now.j);
// 			print_img(param, "./xpm/sand.xpm", next.i, next.j);
// 			if (cnt % 2 == 0)
// 			{
// 				img = mlx_xpm_file_to_image(param->mlx, img_1, &(width), &(height));
// 				if (img == 0)
// 					handle_strerror("No image file");
// 				mlx_put_image_to_window(param->mlx, param->map.mlx_win, img, width * now.j, now.i * height + cnt * 16);
// 			}
// 			else
// 			{
// 				img = mlx_xpm_file_to_image(param->mlx, img_2, &(width), &(height));
// 				if (img == 0)
// 					handle_strerror("No image file");
// 				mlx_put_image_to_window(param->mlx, param->map.mlx_win, img, width * now.j, now.i * height + cnt * 16);
// 			}
// 			cnt++;
// 		}
// 	}
// 	else if (keycode == Keycode_D)
// 	{
// 		img_1 = "./xpm/right_walk_1.xpm";
// 		img_2 = "./xpm/right_walk_2.xpm";
// 		while (cnt <= 4)
// 		{
// 			print_img(param, "./xpm/sand.xpm", now.i, now.j);
// 			print_img(param, "./xpm/sand.xpm", next.i, next.j);
// 			if (cnt % 2 == 0)
// 			{
// 				img = mlx_xpm_file_to_image(param->mlx, img_1, &(width), &(height));
// 				if (img == 0)
// 					handle_strerror("No image file");
// 				mlx_put_image_to_window(param->mlx, param->map.mlx_win, img, width * now.j + cnt * 16, now.i * height);
// 			}
// 			else
// 			{
// 				img = mlx_xpm_file_to_image(param->mlx, img_2, &(width), &(height));
// 				if (img == 0)
// 					handle_strerror("No image file");
// 				mlx_put_image_to_window(param->mlx, param->map.mlx_win, img, width * now.j + cnt * 16, now.i * height);
// 			}
// 			cnt++;
// 		}
// 	}
// 	else if (keycode == Keycode_W)
// 	{
// 		img_1 = "./xpm/up_walk_1.xpm";
// 		img_2 = "./xpm/up_walk_2.xpm";
// 		while (cnt <= 4)
// 		{
// 			print_img(param, "./xpm/sand.xpm", now.i, now.j);
// 			print_img(param, "./xpm/sand.xpm", next.i, next.j);
// 			if (cnt % 2 == 0)
// 			{
// 				img = mlx_xpm_file_to_image(param->mlx, img_1, &(width), &(height));
// 				if (img == 0)
// 					handle_strerror("No image file");
// 				mlx_put_image_to_window(param->mlx, param->map.mlx_win, img, width * now.j, now.i * height - cnt * 16);
// 			}
// 			else
// 			{
// 				img = mlx_xpm_file_to_image(param->mlx, img_2, &(width), &(height));
// 				if (img == 0)
// 					handle_strerror("No image file");
// 				mlx_put_image_to_window(param->mlx, param->map.mlx_win, img, width * now.j, now.i * height - cnt * 16);
// 			}
// 			cnt++;
// 		}
// 	}
// }


// int	move_player(int keycode, t_param *param)
// {
// 	int		cnt;
// 	float	i;
// 	float	j;
// 	t_img 	img;
// 	char	*img_1;
// 	char	*img_2;

// 	cnt = 0;
// 	now = param->elem.player;
// 	while (cnt <= 2)
// 	{
// 		if (keycode == Keycode_A)
// 		{
// 			now.j -= 0.5;
// 			img_1 = "./xpm/left_walk_1.xpm";
// 			img_2 = "./xpm/left_walk_2.xpm";
// 		}
// 		else if (keycode == Keycode_S)
// 		{
// 			now.i += 0.5;
// 			img_1 = "./xpm/down_walk_1.xpm";
// 			img_2 = "./xpm/down_walk_2.xpm";
// 		}
// 		else if (keycode == Keycode_D)
// 		{
// 			now.j += 0.5;
// 			img_1 = "./xpm/right_walk_1.xpm";
// 			img_2 = "./xpm/right_walk_2.xpm";
// 		}
// 		else if (keycode == Keycode_W)
// 		{
// 			now.i -= 0.5;
// 			img_1 = "./xpm/up_walk_1.xpm";
// 			img_2 = "./xpm/up_walk_2.xpm";
// 		}
// 		else
// 			return (0);
// 		cnt++;
// 		if (cnt == 0 || cnt == 2)
// 			img.img = mlx_xpm_file_to_image(param->mlx, img_1, &(img.width), &(img.height));
// 		else
// 			img.img = mlx_xpm_file_to_image(param->mlx, img_2, &(img.width), &(img.height));
// 		if (img.img == 0)
// 			handle_strerror("No image file");
// 		mlx_put_image_to_window(param->mlx, param->map.mlx_win, img.img, now.j * img.width, now.i * img.height);
// 	}
// 	return (1);
// }
