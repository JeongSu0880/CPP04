#include "so_long.h" 

#include <stdio.h>

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}



// // int main(int argc, char *argx[])
// // {
// // 	void	*mlx;
// // 	void	*mlx_win;
// // 	t_data	img;
// // 	int		x;
// // 	int		y;

// // 	x = 0;
// // 	y = 0;
// // 	mlx = mlx_init();
// // 	mlx_win = mlx_new_window(mlx, 900, 625, "Hello world!");
// // 	img.img = mlx_new_image(mlx, 900, 625);
// // 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
// // 	while (x <= 625 && y <= 625)
// // 	{
// // 		my_mlx_pixel_put(&img, x, y, 0x00FF0000);
// // 		x += 1;
// // 		y += 1;
// // 	}
// // 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// // 	mlx_loop(mlx);
// // }

int	set_background(void *mlx, t_map map, t_obj background, t_data *img)
{// 배경인 모래 배경을 화면 전체에 까는 작업.
	int	x;
	int	y;

	x = 0;
	y = 0;
	img->img = mlx_xpm_file_to_image(mlx, "./xpm/sand.xpm", &(background.width), &(background.height));//이렇게.. 넘겨줘도.. 될될까..
	/*error : 해당 이미지 파일이 없을 경우 에러 처리*/
	if (img->img == NULL)
	{
		write(1, "No image file", 13);
		return (0);
	}
	while (y < map.height * 64)
	{
		while (x <= map.width * 64)
		{
			mlx_put_image_to_window(mlx, map.mlx_win, img->img, x, y);
			x += 64;
		}
		x = 0;
		y += 64;
	}
	return (1);
}
int	set_other(void *mlx, t_map map, t_elements *elem, t_data *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (map.height))
	{
		j = 0;
		while (j < (map.width))
		{
			if (map.input[i][j] == '1')
			{
				img->img = mlx_xpm_file_to_image(mlx, "./xpm/stone.xpm", &(elem->wall.width), &(elem->wall.height));
				//없을 경우 error
				mlx_put_image_to_window(mlx, map.mlx_win, img->img, j * 64, i * 64);
			}
			else if (map.input[i][j] == 'P')
			{
				img->img = mlx_xpm_file_to_image(mlx, "./xpm/monkey.xpm", &(elem->player.width), &(elem->player.height));
				//없을 경우 error
				mlx_put_image_to_window(mlx, map.mlx_win, img->img, j * 64, i * 64);
			} 
			else if (map.input[i][j] == 'E')
			{
				img->img = mlx_xpm_file_to_image(mlx, "./xpm/segal.xpm", &(elem->exit.width), &(elem->exit.height));
				//없을 경우 error
				mlx_put_image_to_window(mlx, map.mlx_win, img->img, j * 64, i * 64);
			}
			else if (map.input[i][j] == 'C')
			{
				img->img = mlx_xpm_file_to_image(mlx, "./xpm/strawberry.xpm", &(elem->coin.width), &(elem->coin.height));
				//없을 경우 error
				mlx_put_image_to_window(mlx, map.mlx_win, img->img, j * 64, i * 64);
			}
			else if (!(map.input[i][j] == '0'))
			{
				//에러처리..
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	print_map(void *mlx, t_map map, t_elements *elem, t_data *img)
{//에러처리 해주기
	set_background(mlx, map, elem->background, img);
	set_other(mlx, map, elem, img);
	return (1);
}

#include <stdio.h>//지워야해/

//그냥 테스트 함수이니라.
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

int	main(int argc, char *argv[])
{
	void	*mlx;
	int		fd;
	//OBJECTS	;
	t_data	img;
	t_elements elem;
	t_map	map;
	
	fd = open(argv[1], O_RDONLY);
	if (fd < 0) //TODO : 해당 파일이 없을 시 에러!
	{
		write(1, "map file error!", 15);
		return (0);
	}
	mlx = mlx_init();
	read_and_init_map(mlx, &map, fd);
	test_map(&map);//지워라 고냥 맴 출력 잘 되나 테스트 함수다.
	// map_validity(&map);//만일 아니면 다 프리프리프리픨..
	if (!print_map(mlx, map, &elem, &img))
		return (0);
	// set_wall(mlx, map, &wall, &img);
	mlx_loop(mlx);
	close(fd);
}

//에러 관리를 어떻게 할찌... enum????
