/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:11:47 by jungslee          #+#    #+#             */
/*   Updated: 2023/09/12 19:38:04 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

int	cmp_check(char c, char *base, int *mod)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
		{
			*mod = i;
			return (1);
		}
		i++;
	}
	return (0);
}

int	check_base(char *base, int *digits)
{
	int	i;
	int	j;

	i = 1;
	while (base[i])
	{
		j = 0;
		if ((base[i] == '+') || (base[i] == '-')
			|| ((9 <= base[i] && base[i] <= 13) || base[i] == 32))
			return (0);
		while (j < i)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	*digits = i;
	if (i < 2)
		return (0);
	return (1);
}

void	count_sign(char *str, int *sign_cnt, int *index)
{
	while (str[*index] == '-' || str[*index] == '+')
	{
		if (str[*index] == '-')
			(*sign_cnt)++;
		(*index)++;
	}
}

int	is_valid(char *str, char *base, long long *num)
{
	int	i;
	int	sign_cnt;
	int	digits;
	int	mod;

	i = 0;
	sign_cnt = 0;
	if (check_base(base, &digits) == 0)
		return (0);
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	count_sign(str, &sign_cnt, &i);
	if (!(cmp_check(str[i], base, &mod)))
		return (0);
	while (cmp_check(str[i++], base, &mod))
	{
		*num = (*num) * digits + mod;
	}
	if (sign_cnt % 2)
		*num = -(*num);
	return (1);
}

int	ft_atoi_base(char *str, char *base)
{
	long long	num;

	num = 0;
	if (!(is_valid(str, base, &num)))
		return (0);
	return (num);
}
