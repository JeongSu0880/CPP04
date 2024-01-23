/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:24:59 by jungslee          #+#    #+#             */
/*   Updated: 2023/09/12 19:38:06 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <unistd.h>

int	not_display(char *base, int *len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (base[i])
	{
		if ((base[i] == '+') || (base[i] == '-'))
			return (1);
		j = 0;
		while (j < i)
		{
			if (base[j] == base[i])
				return (1);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (1);
	*len = i;
	return (0);
}

int	display(int nbr, char *base, char len)
{
	long long	nbr_tmp;

	nbr_tmp = nbr;
	if (nbr < 0)
	{
		nbr_tmp = -nbr_tmp;
	}
	if (nbr == 0)
	{
		return (0);
	}
	display(nbr_tmp / len, base, len);
	write(1, &base[nbr_tmp % len], 1);
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	len;

	len = 0;
	if (!not_display(base, &len))
	{
		if (nbr == 0)
		{
			write(1, &base[0], 1);
			return ;
		}
		else if (nbr < 0)
		{
			write(1, "-", 1);
		}
		display(nbr, base, len);
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		num;
	char	*str;

	num = ft_atoi_base(nbr, base_from);
	str
}
