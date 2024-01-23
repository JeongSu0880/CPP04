/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:43:07 by jungslee          #+#    #+#             */
/*   Updated: 2023/08/26 15:50:35 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
void    rush(x, y)
{
	int width;
	int length;

	length = 1;
	while (length <= y)
	{
		width = 1;
		while (width <= x)
		{
			if ((length == 1 || length == y) && (width == 1 || width == x))
				ft_putchar('o');
			else if (length == 1 || length == y)
				ft_putchar('-');
			else if (width == 1 || width == x)
				ft_putchar('|');
			else
				ft_putchar(' ');
			width++;
		}
		ft_putchar('\n');
		length++;
	}
	return ;
}
