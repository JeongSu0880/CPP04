/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:31:43 by jungslee          #+#    #+#             */
/*   Updated: 2023/09/11 16:43:29 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	num;

	num = 1;
	while (num <= nb / num)
	{
		if (num * num == nb)
			return (num);
		num++;
	}
	return (0);
}
/*
#include    <stdio.h>

int main(){
    int result;

    result = ft_sqrt(1073741824);
    printf("%lld", result);
}
*/
