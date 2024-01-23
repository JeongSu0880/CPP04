/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gasong <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:09:02 by gasong            #+#    #+#             */
/*   Updated: 2023/08/26 16:29:11 by gasong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	rush(x, y)
{
	int	width;
	int	length;

	if (!(x >= 0 && y >= 0 && 2147483647 >= x && 2147483647 >= y))
		return ;
	length = 1;
	while (length <= y)
	{
		width = 1;
		while (width <= x)
		{
			if ((width == 1 && length == 1) || (width == x && length == y))
				ft_putchar('/');
			else if ((width == 1 && length == y) || (width == x && length == 1))
				ft_putchar('\\');
			else if ((width == 1 || width == x) || (length == 1 || length == y))
				ft_putchar('*');
			else
				ft_putchar(' ');
			width++;
		}
		ft_putchar('\n');
		length++;
	}
}

int	main(void)
{
	rush(4, 6);
	return (0);
}
