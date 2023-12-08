/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 18:08:06 by jungslee          #+#    #+#             */
/*   Updated: 2023/11/29 14:10:28 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strdup(const char *s)
{
	char	*arr;
	size_t	len;
	size_t	iter;

	len = ft_strlen(s);
	iter = 0;
	arr = (char *)malloc(len * sizeof(char) + 1);
	if (arr == NULL)
		return (0);
	while (iter < len)
	{
		*(arr + iter) = *(s + iter);
		iter++;
	}
	*(arr + iter) = '\0';
	return (arr);
}
/*
#include	<stdio.h>
#include	<string.h>

int	main(void)
{
	char	str[] = "this is a normal test";
	char	*dup;

	dup = ft_strdup(str);
	write(1, dup, ft_strlen(dup));
	free(dup);
}
*/
