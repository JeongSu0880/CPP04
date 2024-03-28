/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:38:05 by jungslee          #+#    #+#             */
/*   Updated: 2024/03/28 21:56:47 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_img(t_param *param, char *str, int i, int j)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(param->mlx, str, \
								&(img.width), &(img.height));
	if (img.img == NULL)
		handle_str_error("No image file");
	mlx_put_image_to_window(param->mlx, param->map.mlx_win, \
							img.img, j * img.width, i * img.height);
}

char	*classify_img(char c, t_coordinate *now)
{
	if (c == '1')
		return ("./textures/stone.xpm");
	else if (c == 'P')
		return ("./textures/sand.xpm");
	else if (c == 'C')
		return ("./textures/strawberry.xpm");
	else if (c == 'B')
		return ("./textures/sand.xpm");
	else
	{
		(now->j)++;
		return (0);
	}
}

char	*sl_strjoin(char *origin, char *new_read, int joint_len)
{
	int		i;
	int		j;
	char	*joint;

	i = 0;
	joint = (char *)malloc(sizeof(char) * (joint_len + 1));
	if (joint == NULL)
		handle_str_error("Malloc error");
	while ((origin != NULL) && (origin[i] != '\0'))
	{
		joint[i] = origin[i];
		i++;
	}
	j = 0;
	while (i < joint_len)
	{
		joint[i] = new_read[j];
		j++;
		i++;
	}
	joint[i] = '\0';
	if (origin != NULL)
		free(origin);
	return (joint);
}

char	*sl_strnbr(int num, int *digit)
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

int	close_win(void)
{
	exit(0);
}
