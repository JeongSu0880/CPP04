/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:39:28 by jungslee          #+#    #+#             */
/*   Updated: 2024/03/21 15:11:50 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_perror()
{
	perror("Error\n");
	exit(-1);
}

int	sl_strlen(char *str)
{
	int	i;

	i = 0;
	while (str != NULL && str[i] != '\0')
		i++;
	return (i);
}

void	handle_strerror(char *str)//TODO 함수명 다시 생각해보기
{
	write(1, "Error!\n", 7);
	write(1, str, sl_strlen(str));
	exit(-1);
}

void	handle_success(void *mlx, t_map *map, t_elements elem)//TODO 이거 해결하고 파라미터 값 고치기
{
	void	*img;
	int		width;
	int		height;

	img = mlx_xpm_file_to_image(mlx, "./xpm/success_bird.xpm", &(width), &(height));
	if (img == NULL)
		handle_strerror("No image file");
	mlx_put_image_to_window(mlx, map->mlx_win, img, width * elem.exit.j, height * elem.exit.i);
	
	
	img = mlx_xpm_file_to_image(mlx, "./xpm/success_sign.xpm", &(width), &(height));
	printf("wid : %d, hei : %d\n", width, height);
	if (img == NULL)
		handle_strerror("No image file");
	mlx_put_image_to_window(mlx, map->mlx_win, img, 64 * (map->width / 2) - width / 2, 64 * (map->height / 2) - height / 2);

	// img = mlx_xpm_file_to_image(mlx, "./xpm/success_2.xpm", &(width), &(height));
	// if (img == NULL)
	// 	handle_strerror("No image file");
	// mlx_put_image_to_window(mlx, map.mlx_win, img, 5 * width, 5 * height);
	// exit(0);
}

void	handle_fail(void *mlx, t_map *map)
{
	void	*img;
	int		width;
	int		height;
	
	write(1, "Fail!\n", 6);
	img = mlx_xpm_file_to_image(mlx, "./xpm/fail_sign.xpm", &(width), &(height));
	printf("wid : %d, hei : %d\n", width, height);
	if (img == NULL)
		handle_strerror("No image file");
	printf("wid : %d hei : %d\n", width, height);
	printf("map = wid : %d hei : %d\n", map->width, map->height);
	mlx_put_image_to_window(mlx, map->mlx_win, img, (64 * map->width / 2) - width / 2, (64 * map->height / 2) - height / 2);
	// img = mlx_xpm_file_to_image(mlx, "./xpm/fail_2.xpm", &(width), &(height));
	// if (img == NULL)
	// 	handle_strerror("No image file");
	// printf("width : %d height : %d\n", width, height);
	// printf("map width : %d map height : %d\n", map->width, map->height);
	// mlx_put_image_to_window(mlx, map->mlx_win, img, (map->width/2) * width, (map->height/2) * height);
	// exit(0);
}