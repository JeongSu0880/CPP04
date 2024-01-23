/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 14:31:19 by jungslee          #+#    #+#             */
/*   Updated: 2023/08/26 15:42:28 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include    <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
    return ;
}

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
            if (length == 1 && (width == 1 || width == x))
                ft_putchar('A');
            else if (length == y && (width == 1 || width == x))
                ft_putchar('C');
            else if (length == 1 || length == y || width == 1 || width == x)
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

int main(void)
{
    rush(7, 10);
    return (0);
}
