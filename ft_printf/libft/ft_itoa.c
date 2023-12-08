/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:39:29 by jungslee          #+#    #+#             */
/*   Updated: 2023/12/04 16:23:25 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

static int	handle_neg(int n, size_t *cnt)
{
	if (n < 0)
	{
		(*cnt)++;
		return (-1);
	}
	return (1);
}

static void	cnt_num(long long tmp_num, size_t *cnt)
{
	while (tmp_num)
	{
		(*cnt)++;
		tmp_num = tmp_num / 10;
	}
}

static void	transfer(char *result, int cnt, int sign, long long tmp)
{
	int	idx;

	idx = cnt - 1;
	while (idx > 0)
	{
		*(result + idx) = tmp % 10 + '0';
		tmp = tmp / 10;
		idx--;
	}
	if (sign == -1)
		*(result + idx) = '-';
	else
		*(result + idx) = tmp % 10 + '0';
	*(result + cnt) = '\0';
}

char	*ft_itoa(int n)
{
	char		*result;
	size_t		cnt;
	long long	tmp;
	int			sign;

	cnt = 0;
	sign = handle_neg(n, &cnt);
	tmp = (long long)n * sign;
	cnt_num(tmp, &cnt);
	if (!tmp)
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
		transfer(result, cnt, sign, tmp);
	}
	return (result);
}
/*
#include	<stdio.h>

int main(void)
{
	char	*num = ft_itoa(-123456);
	printf("%s\n", num);

	free(num);
}
*/
