/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:32:46 by jungslee          #+#    #+#             */
/*   Updated: 2023/09/11 16:51:31 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

int	ft_abs(int num)
{
	if (num < 0)
		num = -num;
	return (num);
}

int	promising(int *queens, int row, int index)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (queens[i] == queens[row])
			return (0);
		if (ft_abs(i - row) == ft_abs(queens[i] - index))
			return (0);
		i++;
	}
	return (1);
}

void	print_queens(int *queens)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		write(1, &"0123456789"[queens[i]], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	set_row(int *queens, int row, int *cnt)
{
	int	i;

	i = 0;
	if (row == 10)
	{
		print_queens(queens);
		(*cnt)++;
		return ;
	}
	while (i < 10)
	{
		queens[row] = i;
		if (promising(queens, row, i))
		{
			set_row(queens, row + 1, cnt);
		}
		else
			queens[row] = -1;
		i++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	cnt;
	int	queens[11];
	int	row;

	row = 0;
	cnt = 0;
	set_row(queens, row, &cnt);
	return (cnt);
}
/*
#include    <stdio.h>

int main()
{
    int n = ft_ten_queens_puzzle();
    printf("%d", n);
}
*/
