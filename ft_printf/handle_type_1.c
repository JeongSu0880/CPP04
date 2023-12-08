/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_type_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 17:01:53 by jungslee          #+#    #+#             */
/*   Updated: 2023/12/08 14:34:20 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "ft_printf.h"

char	*handle_c(va_list ap, int *c_flag)
{
	char	*result;
	int		c;

	c = va_arg(ap, int);
	    //default argument promotion -> 옛날에는 int로 타입 캐스팅했다.
	if (!ft_isprint(c))
	{
		if (write(1, &c, 1) == -1)
			return (0);
		*c_flag = 1;
		return (0);
	}
	else
	{
		result = (char *)malloc(sizeof(char) * 2);
		if (result == NULL)
			return (0);
		*result = c;
		*(result + 1) = '\0';
	}
	return (result);
}

char	*handle_s(va_list ap)
{
	char	*result;
	char	*s;
	int		str_len;

	s = va_arg(ap, char *);
	if (s == NULL)
	{
		result = (char *)malloc(sizeof(char) * 7);
		if (result == NULL)
			return (0);
		ft_strlcpy(result, "(null)", 7);
	}
	else
	{
		str_len = ft_strlen(s);
		result = (char *)malloc(sizeof(char) * (str_len + 1));
		if (result == NULL)
			return (0);
		ft_strlcpy(result, s, str_len + 1);
	}
	return (result);
}

char	*handle_p(va_list ap)
{
	char	*result;
	void	*p;
	char	*trans_p;

	p = va_arg(ap, void *);
	trans_p = ft_itoa_hex((uintptr_t)p);
	if (trans_p == NULL)
		return (0);
	result = ft_strjoin("0x", trans_p);
	free(trans_p);
	if (result == NULL)
		return (0);
	return (result);
}
