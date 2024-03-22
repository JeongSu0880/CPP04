/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 21:49:36 by jungslee          #+#    #+#             */
/*   Updated: 2024/03/20 17:03:28 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
1. 직사각형인지 ok -> map_init.c 의 read_and_init_map에서 미리 거름
2. 구성요소 개수 ok
3. 다른 문자가 섞였는지 -> 2, 3은 같이 할 수 있을 듯 ok
4. 유효한 경로가 하나는 있는지
5. 가장자리가 모두 벽인지 ok
*/

void	check_edge(t_map map) //가장자리 검사 함수
{
	int	x;
	int	y;
	char	*str;

	x = 0;
	y = 0;
	str = "Wrong map input : Edge error";
	while (x < map.height)
	{
		if (map.input[x][0] != '1')
			handle_strerror(str);
		if (map.input[x][map.width - 1] != '1')
			handle_strerror(str);
		x++;
	}
	while (y < map.width)
	{
		if (map.input[0][y] != '1')
			handle_strerror(str);
		if (map.input[map.height - 1][y] != '1')
			handle_strerror(str);
		y++;
	}
}

void	change_elem_info(t_coordinate *to_change, int *count, t_coordinate now)
{
	(*count)++;
	*(to_change) = now;
}

//TODO 함수 줄 줄이기
void	count_elem(t_map map, t_elements *p_elem, int *p_count, int *e_count)
{//TODO enemy의 개수가 필요할까?
	t_coordinate	idx;
	char	now;

	idx.i = 0;
	p_elem->collect = 0;
	p_elem->enemy = 0;
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
			else if (!(now == '1' || now == '0' || now == '\n' || now == 'B'))
				handle_strerror("Wrong map input : Invalid character");
			idx.j++;
		}
		idx.i++;
	}
}

void	check_elem(t_map map, t_elements *p_elem)
{
	int		idx;
	char	now;
	int		p_count;
	int		e_count;

	idx = 0;
	p_count = 0;
	e_count = 0;
	count_elem(map, p_elem, &p_count, &e_count);
	if (p_count != 1 || \
		e_count != 1 || \
		p_elem->collect < 1)
		handle_strerror("Wrong map input : Wrong number of elements");
}

void	push(t_coordinate *stack, int i, int j, int *top)
{
	t_coordinate	add;

	add.i = i;
	add.j = j;
	(*top)++;
	stack[*top] = add;
}

t_coordinate	pop(t_coordinate *stack, int *top)
{
	t_coordinate	result;

	result = stack[*top];
	(*top)--;
	return (result);
}

char **copy_map(t_map map)
{
	char **result;
	int	i;
	int j;

	i = 0;
	result = (char **)malloc(sizeof(char *) * map.height);
	while (i < map.height)
	{
		j = 0;
		result[i] = (char *)malloc(sizeof(char) * map.width);
		while (j < map.width)
		{
			result[i][j] = map.input[i][j];
			j++;
		}
		i++;
	}
	return (result);
}

void	update_and_add(char **map, int i, int j, int *pushed)
{
	if (map[i][j] != 'E')
		map[i][j] = '1';
	(*pushed)++;
}



int	push_surround(char **map, t_coordinate *stack, int *top_idx, t_coordinate now)
{
	int pushed;

	pushed = 0;
	map[now.i][now.j] = '1';
	if (map[now.i - 1][now.j] != '1' && map[now.i - 1][now.j] != 'B')
	{
		push(stack, now.i - 1, now.j, top_idx);
		update_and_add(map, now.i - 1, now.j, &pushed);
	}
	if (map[now.i][now.j - 1] != '1' && map[now.i][now.j - 1] != 'B')
	{
		push(stack, now.i, now.j - 1, top_idx);
		update_and_add(map, now.i, now.j - 1, &pushed);
	}
	if (map[now.i + 1][now.j] != '1' && map[now.i + 1][now.j] != 'B')
	{
		push(stack, now.i + 1, now.j, top_idx);
		update_and_add(map, now.i + 1, now.j, &pushed);
	}
	if (map[now.i][now.j + 1] != '1' && map[now.i][now.j + 1] != 'B')
	{
		push(stack, now.i, now.j + 1, top_idx);
		update_and_add(map, now.i + 1, now.j, &pushed);
	}
	return (pushed);
}

void	check_path(t_map map, t_elements elem)
{
	char **copy;
	t_coordinate	*stack;
	t_coordinate	now;
	int				top_idx;
	int				surround;

	stack = (t_coordinate *)malloc(sizeof(t_coordinate) * map.width * map.height);//TODO 좀 더 할당의 크기를 줄이는 방법이 있을까?
	copy = copy_map(map);
	now = elem.player;
	top_idx = -1;
	surround = 0;
	while ((now.i < map.height) && (now.j < map.width))
	{
		if (top_idx > -1)
			now = pop(stack, &top_idx);
		if (copy[now.i][now.j] == 'E')
			break;
		surround = push_surround(copy, stack, &top_idx, now);
		if (top_idx == -1 && surround == 0)
			handle_strerror("Wrong map input : No valid path");
	}
}

void	check_map_validity(t_map map, t_elements *p_elem)
{
	check_edge(map);
	check_elem(map, p_elem);
	check_path(map, *p_elem);
}
