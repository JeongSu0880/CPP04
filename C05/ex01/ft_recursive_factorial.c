/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:30:03 by jungslee          #+#    #+#             */
/*   Updated: 2023/09/11 16:39:27 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_factorial(int nb)
{
	long long	fac;

	fac = 1;
	if (nb < 0)
		return (0);
	else if (nb == 0 || nb == 1)
		return (1);
	else
	{
		fac = ft_recursive_factorial(nb - 1) * nb;
	}
	return (fac);
}
/*
#include    <stdio.h>

int main()
{
    printf("%d ", ft_recursive_factorial(5));
}
*/
