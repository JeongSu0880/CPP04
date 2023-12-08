/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 21:41:19 by jungslee          #+#    #+#             */
/*   Updated: 2023/12/05 17:47:34 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "ft_printf.h"

static void	write_error(const void *buf, int *len, char letter, int c_flag)
{
	if (buf == 0 && c_flag == 1)
		*len = 1;
	else if (buf == 0)
		*len = -1;
	else if (write(1, buf, ft_strlen(buf)) == -1)
		*len = -1;
	else if (letter == 'c' && ft_strlen(buf) == 0)
		*len = 1;
	else
		*len = ft_strlen(buf);
}

int	detect_type(va_list ap, char *letter)
{
	char	*result;
	int		len;
	int		c_flag;

	c_flag = 0;
	if (*letter == 'c')
		result = handle_c(ap, &c_flag);
	else if (*letter == 's')
		result = handle_s(ap);
	else if (*letter == 'p')
		result = handle_p(ap);
	else if (*letter == 'd' || *letter == 'i')
		result = handle_id(ap);
	else if (*letter == 'u')
		result = handle_u(ap);
	else if (*letter == 'x' || *letter == 'X')
		result = handle_x(ap, *letter);
	else if (*letter == '%')
		result = handle_percent("%");
	else
		return (-2);
	write_error(result, &len, *letter, c_flag);
	free(result);
	return (len);
}
