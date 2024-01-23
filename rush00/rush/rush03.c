/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:31:19 by jungslee          #+#    #+#             */
/*   Updated: 2023/08/26 16:05:34 by siryu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include    <unistd.h>

void	rush03(x, y)
{
	int	width;
	int	length;

	length = 1;
	while (length <= y)
	{
		width = 1;
		while (width <= x)
		{
			if (width == 1 && (length == 1 || length == y))
				ft_putchar('A');
			else if (width == x && (length == 1 || length == y))
				ft_putchar('C');
			else if (width == 1 || width == x || length == 1 || length == y)
				ft_putchar('B');
			else
				ft_putchar(' ');
			width++;
		}
		ft_putchar('\n');
		length++;
	}
	return ;
}
