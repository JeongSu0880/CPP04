#include "so_long.h" 
//TODO exit 에서의 처리... 프레임 나눠서 움직임 자연스럽게... 화면 확대 축소 가능하게, 과제의 [그래픽] 관련 처리!

void	print_background(void *mlx, t_map map)
{
	int	x;
	int	y;
	int	width;
	int height;
	void	*img;

	x = 0;
	y = 0;
	width = IMG_WIDTH;
	height = IMG_HEIGHT;
	img = mlx_xpm_file_to_image(mlx, "./xpm/sand.xpm", &(width), &(height));//TODO 이렇게 넘겨줘도 될까?
	if (img == NULL)
		handle_strerror("No image file");
	while (y < map.height * IMG_HEIGHT)
	{
		while (x <= map.width * IMG_HEIGHT)
		{
			mlx_put_image_to_window(mlx, map.mlx_win, img, x, y);
			x += IMG_WIDTH;
		}
		x = 0;
		y += IMG_HEIGHT;
	}
}

char	*classify_img(char c, int *j)
{
	if (c == '1')
		return ("./xpm/stone.xpm");
	else if (c == 'P')
		return ("./xpm/monkey.xpm");
	else if (c == 'C')
		return ("./xpm/strawberry.xpm");
	else if (c == 'B')
		return ("./xpm/banana.xpm");
	else
	{
		(*j)++;
		return (0);
	}
}

void print_other_and_count(void *mlx, t_map map, t_elements *elem)
{
	t_coordinate	now;
	void	*img;
	int		width;
	int		height;
	char	*str;

	now.i = 0;
	now.j = 0;
	img = mlx_xpm_file_to_image(mlx, "./xpm/segal.xpm", &(width), &(height));
	if (img == NULL)
		handle_strerror("No image file");
	mlx_put_image_to_window(mlx, map.mlx_win, img, (elem->exit.j) * (width), (elem->exit.i) * (width));
	while (now.i < (map.height))
	{
		now.j = 0;
		while (now.j < (map.width))
		{
			str = classify_img(map.input[now.i][now.j], &now.j);
			if (str == 0)
				continue ;
			img = mlx_xpm_file_to_image(mlx, str, &(width), &(height));
			if (img == NULL)//TODO ERROR : 이미지 파일이 없을 경우 에러
				handle_strerror("No image file");
			mlx_put_image_to_window(mlx, map.mlx_win, img, now.j * (width), now.i * (width));
			now.j++;
		}
		now.i++;
	}
}

void	print_map(void *mlx, t_map map, t_elements *elem)
{
	print_background(mlx, map);
	print_other_and_count(mlx, map, elem);
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

void check_now(t_param *param)
{
	t_coordinate	now;
	t_coordinate	exit;

	exit = param->elem.exit;
	now = param->elem.player;
	if ((now.i == exit.i) && (now.j == exit.j))
	{
		if (param->elem.collect == 0)
			handle_success(param->mlx, param->map);
		else
		{
			write(1, "need more strawberries!\n", 25);
		}
	}
}

void	sl_putnbr(int num)
{
	char	c;

	if (num == 0)
		return ;
	sl_putnbr(num / 10);
	c = num % 10 + '0';
	write(1, &c, 1);
}

int	key_hook(int keycode, t_param *param)
{
	t_coordinate	now;
	t_coordinate	next;
	t_map			map;

	now = param->elem.player;
	map = param->map;
	next = now;;
	// print_map(param->mlx, param->map, &(param->elem));
	if (keycode == 13)
		next.i -= 1;
	else if (keycode == 0)
		next.j -= 1;
	else if (keycode == 1)
		next.i += 1;
	else if (keycode == 2)
		next.j += 1;
	else if (keycode == 53)
		exit(0);
	else
		return (0);
	if (map.input[next.i][next.j] == '1')
		return (0);
	else if (map.input[next.i][next.j] == 'C')
		param->elem.collect--;
	else if (map.input[next.i][next.j] == 'B')
		handle_fail(param->mlx, param->map);
	param->move++;
	sl_putnbr(param->move);
	write(1, "\n", 1);
	// check_now(param);
	swap_locat(&map, &(param->elem), next);
	print_map(param->mlx, param->map, &(param->elem));
	check_now(param);
	return (0);
}


int	main(int argc, char *argv[])
{
	int		fd;
	t_param		param;
	
	fd = open(argv[1], O_RDONLY);
	if (fd < 0) //TODO : 해당 파일이 없을 시 에러!
		handle_perror();
	param.mlx = mlx_init();
	read_and_init_map(param.mlx, &(param.map), fd);
	check_map_validity(param.map, &(param.elem));
	print_map(param.mlx, param.map, &(param.elem));
	param.move = 0;
	// mlx_key_hook(param.map.mlx_win, key_hook, &(param));
	mlx_hook(param.map.mlx_win, 2, 0, key_hook, &(param));
	// check_now(&param);
	mlx_loop(param.mlx);
	close(fd);
}
