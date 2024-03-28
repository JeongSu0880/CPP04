/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:30:24 by jungslee          #+#    #+#             */
/*   Updated: 2024/03/27 21:42:04 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	update_and_add(char **map, int i, int j, char dest)
{
	if (map[i][j] != dest)
		map[i][j] = '1';
	return (1);
}

int	push_surround(char **map, t_stack *stack, t_coordinate now, char dest)
{
	int	pushed;

	pushed = 0;
	map[now.i][now.j] = '1';
	if (map[now.i - 1][now.j] != '1')
	{
		push(stack->stack, now.i - 1, now.j, &(stack->top));
		pushed += update_and_add(map, now.i - 1, now.j, dest);
	}
	if (map[now.i][now.j - 1] != '1')
	{
		push(stack->stack, now.i, now.j - 1, &(stack->top));
		pushed += update_and_add(map, now.i, now.j - 1, dest);
	}
	if (map[now.i + 1][now.j] != '1')
	{
		push(stack->stack, now.i + 1, now.j, &(stack->top));
		pushed += update_and_add(map, now.i + 1, now.j, dest);
	}
	if (map[now.i][now.j + 1] != '1')
	{
		push(stack->stack, now.i, now.j + 1, &(stack->top));
		pushed += update_and_add(map, now.i + 1, now.j, dest);
	}
	return (pushed);
}
