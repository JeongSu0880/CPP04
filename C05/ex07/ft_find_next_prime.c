/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:32:35 by jungslee          #+#    #+#             */
/*   Updated: 2023/09/11 16:48:10 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(long long nb)
{
	int	i;

	i = 2;
	if (nb == 0 || nb == 1)
		return (0);
	while (i < nb / i)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 0)
	{
		return (2);
	}
	while (!ft_is_prime((long long)nb))
	{
		nb++;
	}
	return (nb);
}
/*
#include    <stdio.h>
int main()
{
    printf("%d", ft_find_next_prime(2147483640));
}
*/
