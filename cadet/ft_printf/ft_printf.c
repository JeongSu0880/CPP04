/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:11:21 by jungslee          #+#    #+#             */
/*   Updated: 2023/12/04 15:30:26 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "ft_printf.h"

static int	write_str(char **letter, int *len)
{
	while ((**letter) != '%')
	{
		if (write(1, *letter, 1) == -1)
			return (-1);
		(*len)++;
		(*letter)++;
		if (**letter == '\0')
			return (*len);
	}
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*letter;
	int		len;
	int		format_tmp;
	int		ret_write_str;

	if (*format == '\0')
		return (0);
	len = 0;
	letter = (char *)format;
	va_start(ap, format);
	while (*letter != '\0')
	{
		ret_write_str = write_str(&letter, &len);
		if (ret_write_str != 0)
			return (ret_write_str);
		format_tmp = detect_type(ap, ++letter);
		if (format_tmp == -1)
			return (-1);
		len += format_tmp;
		letter++;
	}
	va_end(ap);
	return (len);
}

// #include	<stdio.h>
// int main()
// {
// 	char 	c = 'a';
// 	char	*s1 = NULL;
// 	char	*s2 = NULL;
// 	int		d = 1;
// 	int		i = 2;
// 	unsigned int	u = -2;
// 	int		x = 234;
// 	int		X = 234;
// 	void	*p = NULL;

// 	// printf("return : %d \n", printf(" %yz\n"));
// 	// ft_printf("return : %d \n", ft_printf(" %yz\n"));

// 	// printf("return : %d \n", printf("p %% %%\n"));	
// 	// printf("return : %d \n", ft_printf("ft %% %% \n"));
// }
