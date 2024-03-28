/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:24:28 by jungslee          #+#    #+#             */
/*   Updated: 2024/03/27 21:39:18 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**copy_map(t_map map)
{
	char	**result;
	int		i;
	int		j;

	i = 0;
	result = (char **)malloc(sizeof(char *) * map.height);
	if (result == 0)
		handle_str_error("Malloc error!");
	while (i < map.height)
	{
		j = 0;
		result[i] = (char *)malloc(sizeof(char) * map.width);
		if (result[i] == 0)
			handle_str_error("Malloc error!");
		while (j < map.width)
		{
			result[i][j] = map.input[i][j];
			j++;
		}
		i++;
	}
	return (result);
}

void	map_free(char **map, int map_i)
{
	int	i;

	i = 0;
	while (i < map_i)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void	init_check_path(t_map map, t_elements elem, t_coordinate *now, \
						t_stack *stack)
{
	*now = elem.player;
	stack->stack = (t_coordinate *)malloc(sizeof(t_coordinate) * \
					map.width * map.height);
	stack->top = -1;
}

void	check_path(t_map map, t_elements elem, char dest, t_coordinate *checked)
{
	char			**copy;
	t_coordinate	now;
	t_stack			stack;
	int				surround;

	if (stack.stack == 0)
		handle_str_error("Malloc error");
	copy = copy_map(map);
	surround = 0;
	init_check_path(map, elem, &now, &stack);
	while ((now.i < map.height) && (now.j < map.width))
	{
		if (stack.top > -1)
			now = pop(stack.stack, &(stack.top));
		if (copy[now.i][now.j] == dest)
		{
			*checked = now;
			map_free(copy, map.height);
			break ;
		}
		surround = push_surround(copy, &stack, now, dest);
		if (stack.top == -1 && surround == 0)
			handle_str_error("Wrong map input : No valid path");
	}
	free(stack.stack);
}
