/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:41:02 by jungslee          #+#    #+#             */
/*   Updated: 2023/11/02 19:50:44 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;

	src_len = 0;
	while (src[src_len])
		src_len++;
	if (src_len + 1 <= size)
	{
		ft_memmove(dest, src, src_len);
		*(dest + src_len) = '\0';
	}
	else if (size >= 1)
	{
		ft_memmove(dest, src, size - 1);
		*(dest + size - 1) = '\0';
	}
	return (src_len);
}
/*
#include <string.h>
#include <stdio.h>
int main(void)
{
	char dest1[9] = "applepie";
	char dest2[9] = "applepie";
	const char src[6] = "peach";
	int i = 0;;
	printf("strlcpy_return : %lu\n", strlcpy(dest1, src, 8));
	printf("ft_strlcpy_return : %lu\n", ft_strlcpy(dest2, src, 8));
	printf("strlcpy : %s\n", dest1);
	printf("ft_strlcpy : %s\n", dest2);
	char dest3[9] = "applepie";
	char dest4[9] = "applepie";
	printf("strlcpy_return : %lu\n", strlcpy(dest3, src, 0));
	printf("ft_strlcpy_return : %lu\n", ft_strlcpy(dest4, src, 0));
	while (i < 9)
	{
		printf("strlcpy : %c\n", dest3[i++]);
	}
	printf("\n");
	i = 0;
	while (i < 9)
	{
		printf("ft_strlcpy : %c\n", dest4[i++]);
	}
	return(0);
}
*/
