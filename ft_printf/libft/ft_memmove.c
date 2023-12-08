/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 18:28:31 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/21 20:29:53 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	size_t			len;

	if (src == dest)
		return (dest);
	if (src < dest)
	{
		len = num;
		while (len > 0)
		{
			--len;
			*(unsigned char *)(dest + len) = *(unsigned char *)(src + len);
		}
	}
	else
	{
		len = 0;
		while (len < num)
		{
			*(unsigned char *)(dest + len) = *(unsigned char *)(src + len);
			len++;
		}
	}
	return (dest);
}
/*
#include	<string.h>
#include	<stdio.h>

int	main(void)
{
	char	str1[] = "aaaaaaaAa";
	char	str2[] = "bbbbbb";
	char 	*result1 = ft_memmove(str1, str2, 5);
	char	*result2 = memmove(str1, str2, 5);

	printf("ft : %s\n", result1);
	printf("original : %s\n", result2);
}
*/
