/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:05:16 by jungslee          #+#    #+#             */
/*   Updated: 2023/09/13 16:25:37 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int			i;
	long long	ret;

	i = 0;
	if (max <= min)
	{
		*range = NULL;
		return (0);
	}
	ret = max - min;
	*range = (int *)malloc(sizeof(int) * (max - min));
	if (*range == NULL)
		return (-1);
	while (min < max)
	{
		(*range)[i] = min;
		min++;
		i++;
	}
	return (ret);
}
/*
#include    <stdio.h>

int main()
{
    int **arr;
    int n = ft_ultimate_range(arr, 5, 10);
    printf("%d", n);
}
*/
