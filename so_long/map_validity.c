/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 21:49:36 by jungslee          #+#    #+#             */
/*   Updated: 2024/03/28 21:16:33 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_edge(t_map map)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = "Wrong map input : Edge error";
	while (i < map.height)
	{
		if (map.input[i][0] != '1')
			handle_str_error(str);
		if (map.input[i][map.width - 1] != '1')
			handle_str_error(str);
		i++;
	}
	while (j < map.width)
	{
		if (map.input[0][j] != '1')
			handle_str_error(str);
		if (map.input[map.height - 1][j] != '1')
			handle_str_error(str);
		j++;
	}
}

static void	change_elem_info(t_coordinate *to_change, \
						int *count, t_coordinate now)
{
	(*count)++;
	*(to_change) = now;
}

static void	count_elem(t_map map, t_elements *p_elem, \
						int *p_count, int *e_count)
{
	t_coordinate	idx;
	char			now;

	idx.i = 0;
	while (idx.i < map.height)
	{
		idx.j = 0;
		while (idx.j < map.width)
		{
			now = map.input[idx.i][idx.j];
			if (now == 'P')
				change_elem_info(&(p_elem->player), p_count, idx);
			else if (now == 'E')
				change_elem_info(&(p_elem->exit), e_count, idx);
			else if (now == 'C')
				p_elem->collect++;
			else if (now == 'B')
				p_elem->enemy_cnt++;
			else if (!(now == '1' || now == '0' || now == '\n' || now == 'B'))
				handle_str_error("Wrong map input : Invalid character");
			idx.j++;
		}
		idx.i++;
	}
}

static void	check_elem(t_map map, t_elements *p_elem)
{
	int		idx;
	int		p_count;
	int		e_count;

	idx = 0;
	p_count = 0;
	e_count = 0;
	p_elem->collect = 0;
	p_elem->enemy_cnt = 0;
	count_elem(map, p_elem, &p_count, &e_count);
	if (p_count != 1 || \
		e_count != 1 || \
		p_elem->collect < 1)
		handle_str_error("Wrong map input : Wrong number of elements");
}

void	check_map_validity(t_map map, t_elements *p_elem)
{
	int				collect_cnt;
	t_coordinate	checked;
	t_map			copy;

	if (map.height > WIN_HEIGHT_MAX || map.width > WIN_WIDTH_MAX)
		handle_str_error("Map is too big!");
	copy.input = copy_map(map);
	copy.height = map.height;
	copy.width = map.width;
	collect_cnt = 0;
	check_edge(map);
	check_elem(map, p_elem);
	check_path(copy, *p_elem, 'E', &checked);
	copy.input[checked.i][checked.j] = '0';
	while (collect_cnt < p_elem->collect)
	{
		check_path(copy, *p_elem, 'C', &checked);
		copy.input[checked.i][checked.j] = '0';
		collect_cnt++;
	}
	map_free(copy.input, copy.height);
}
