/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:03:27 by jungslee          #+#    #+#             */
/*   Updated: 2023/09/12 13:04:40 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	if ((max - min) <= 0)
		return (0);
	i = 0;
	arr = (int *)malloc(sizeof(int) * (max - min));
	if (arr == NULL)
	{
		return (0);
	}
	while (min < max)
	{
		arr[i] = min++;
		i++;
	}
	return (arr);
}
/*
#include    <stdio.h>

int main()
{
    int *str;
    int i;

    i = 0;
    str = ft_range(5, 10);
    while (str[i] != '\0')
    {
        printf("%d ", str[i]);
        i++;
    }
    free(str);
    return (0);
}
*/
