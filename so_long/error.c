/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 17:39:28 by jungslee          #+#    #+#             */
/*   Updated: 2024/03/17 21:51:43 by jungslee         ###   ########.fr       */
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

void	handle_success(void *mlx, t_map map)
{
	void	*img;
	int		width;
	int		height;
	

	write(1, "Success!\n", 9);
	// img = mlx_xpm_file_to_image(mlx, "./xpm/success_1_.xpm", &(width), &(height));
	// if (img == NULL)
	// 	handle_strerror("No image file");
	// mlx_put_image_to_window(mlx, map.mlx_win, img, (map.width/2), (map.height / 2));
	exit(0);
}

void	handle_fail(void *mlx, t_map map)
{
	void	*img;
	int		width;
	int		height;
	
	write(1, "Fail!\n", 5);
	// img = mlx_xpm_file_to_image(mlx, "./xpm/success_1_.xpm", &(width), &(height));
	// if (img == NULL)
	// 	handle_strerror("No image file");
	// mlx_put_image_to_window(mlx, map.mlx_win, img, (map.width / 2), (map.height / 2));
	exit(0);
}