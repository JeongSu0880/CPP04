/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_type_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:31:18 by jungslee          #+#    #+#             */
/*   Updated: 2023/12/04 16:18:45 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "ft_printf.h"

char	*handle_id(va_list ap)
{
	char	*result;
	int		d;

	d = va_arg(ap, int);
	result = ft_itoa(d);
	if (result == NULL)
		return (0);
	return (result);
}

char	*handle_u(va_list ap)
{
	char			*result;
	unsigned int	u;

	u = (unsigned int)va_arg(ap, int);
	result = ft_itoa_u(u);
	if (result == NULL)
		return (0);
	return (result);
}

char	*handle_x(va_list ap, char letter)
{
	char			*result;
	unsigned int	x;
	int				idx;

	idx = 0;
	x = va_arg(ap, unsigned int);
	result = ft_itoa_hex(x);
	if (result == NULL)
		return (0);
	if (letter == 'X')
	{
		while (*(result + idx))
		{
			if (97 <= *(result + idx) && *(result + idx) <= 122)
				*(result + idx) = ft_toupper(*(result + idx));
			idx++;
		}
	}
	return (result);
}

char	*handle_percent(char *percent)
{
	char	*result;

	result = ft_strdup(percent);
	if (result == NULL)
		return (0);
	return (result);
}
