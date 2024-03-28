/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:56:13 by jungslee          #+#    #+#             */
/*   Updated: 2024/03/28 21:56:47 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	handle_perror(void)
{
	perror("Error\n");
	exit(-1);
}

static int	sl_strlen(char *str)
{
	int	i;

	i = 0;
	while (str != NULL && str[i] != '\0')
		i++;
	return (i);
}

void	handle_str_error(char *str)
{
	write(1, "Error!\n", 7);
	write(1, str, sl_strlen(str));
	exit(-1);
}

void	handle_success(void *mlx, t_map *map, t_elements elem)
{
	void	*img;
	int		width;
	int		height;

	write(1, "Success!\n", 9);
	img = mlx_xpm_file_to_image(mlx, "./textures/success_bird.xpm", \
								&(width), &(height));
	if (img == NULL)
		handle_str_error("No image file");
	mlx_put_image_to_window(mlx, map->mlx_win, img, width * elem.exit.j, \
							height * elem.exit.i);
	img = mlx_xpm_file_to_image(mlx, "./textures/success_sign.xpm", \
								&(width), &(height));
	if (img == NULL)
		handle_str_error("No image file");
	mlx_put_image_to_window(mlx, map->mlx_win, img, \
				IMG_WIDTH * (map->width / 2) - width / 2, \
				IMG_HEIGHT * (map->height / 2) - height / 2);
}

int	handle_fail(void *mlx, t_map *map)
{
	void	*img;
	int		width;
	int		height;

	write(1, "Fail!\n", 6);
	img = mlx_xpm_file_to_image(mlx, "./textures/fail_sign.xpm", \
						&(width), &(height));
	if (img == NULL)
		handle_str_error("No image file");
	mlx_put_image_to_window(mlx, map->mlx_win, img, \
				IMG_WIDTH * (map->width / 2) - width / 2, \
				IMG_HEIGHT * (map->height / 2) - height / 2);
	return (0);
}
