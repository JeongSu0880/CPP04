/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 20:11:21 by jungslee          #+#    #+#             */
/*   Updated: 2023/12/05 17:53:33 by jungslee         ###   ########.fr       */
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

void	init(int *len, char **letter, const char *format)
{
	char	*tmp;

	tmp = (char *)format;
	*letter = tmp;
	*len = 0;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*letter;
	int		len;
	int		format_len;
	int		ret_write_str;

	if (*format == '\0')
		return (0);
	init(&len, &letter, format);
	va_start(ap, format);
	while (*letter != '\0')
	{
		ret_write_str = write_str(&letter, &len);
		if (ret_write_str != 0)
			return (ret_write_str);
		format_len = detect_type(ap, ++letter);
		if (format_len == -1)
			return (-1);
		if (format_len == -2)
			continue ;
		len += format_len;
		letter++;
	}
	va_end(ap);
	return (len);
}

// #include    <stdio.h>
// int main()
// {
//     char    c = 'a';
//     char    *s1 = NULL;
//     char    *s2 = NULL;
//     int     d = 1;
//     int     i = 2;
//     unsigned int    u = -2;
//     int     x = 234;
//     int     X = 234;
//     void    *p = NULL;
//
//     // printf("return : %d \n", printf("%y\n", c));
//     // ft_printf("return : %d \n", ft_printf("%y\n", c));
//
//
//     // // printf("return : %d \n", printf("% s\n", s1));
//     // // ft_printf("return : %d \n", ft_printf("% s\n", s1));
//
// 	// printf("%@@@s\n", s1);
// 	// ft_printf("%@@@s\n", s1);
//
//
//     // printf("return : %d \n", printf("%c\n", c));
//     // ft_printf("return : %d \n", ft_printf("%c\n", c));
//
//     // printf("return : %d \n", printf("p %% %%\n"));   
//     // printf("return : %d \n", ft_printf("ft %% %% \n"));
// }