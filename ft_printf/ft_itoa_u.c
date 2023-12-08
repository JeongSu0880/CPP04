/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:16:39 by jungslee          #+#    #+#             */
/*   Updated: 2023/12/05 17:15:05 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "ft_printf.h"

static void	cnt_num(unsigned int num, size_t *cnt)
{
	while (num)
	{
		(*cnt)++;
		num = num / 10;
	}
}

static void	transfer(char *result, int cnt, unsigned int n)
{
	int	idx;

	idx = cnt - 1;
	while (idx >= 0)
	{
		*(result + idx) = n % 10 + '0';
		n = n / 10;
		idx--;
	}
	*(result + cnt) = '\0';
}

char	*ft_itoa_u(unsigned int n)
{
	char		*result;
	size_t		cnt;

	cnt = 0;
	cnt_num(n, &cnt);
	if (!n)
	{
		result = (char *)malloc(sizeof(char) * 2);
		if (result == NULL)
			return (0);
		*result = '0';
		*(result + 1) = '\0';
	}
	else
	{
		result = (char *)malloc(sizeof(char) * (cnt + 1));
		if (result == NULL)
			return (0);
		transfer(result, cnt, n);
	}
	return (result);
}
