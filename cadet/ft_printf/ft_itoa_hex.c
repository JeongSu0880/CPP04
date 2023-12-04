/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:10:00 by jungslee          #+#    #+#             */
/*   Updated: 2023/12/04 16:18:07 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "ft_printf.h"

static void	cnt_num(uintptr_t num, size_t *cnt)
{
	while (num)
	{
		(*cnt)++;
		num = num / 16;
	}
}

static void	transfer(char *result, int cnt, uintptr_t n)
{
	int	idx;

	idx = cnt - 1;
	while (idx >= 0)
	{
		*(result + idx) = "0123456789abcdef"[n % 16];
		n = n / 16;
		idx--;
	}
	*(result + cnt) = '\0';
}

char	*ft_itoa_hex(uintptr_t n)
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
