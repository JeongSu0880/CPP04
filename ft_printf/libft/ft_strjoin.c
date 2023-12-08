/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 21:18:26 by jungslee          #+#    #+#             */
/*   Updated: 2023/11/04 15:13:07 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*arr;
	size_t	s1_idx;
	size_t	s2_idx;
	size_t	len;

	s1_idx = 0;
	s2_idx = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (arr == NULL)
		return (0);
	while (s1_idx < len)
	{
		if (s1_idx < ft_strlen(s1))
			*(arr + s1_idx) = *(s1 + s1_idx);
		else if (*(s2 + s2_idx))
		{
			*(arr + s1_idx) = *(s2 + s2_idx);
			s2_idx++;
		}
		s1_idx++;
	}
	*(arr + s1_idx) = '\0';
	return (arr);
}
/*
#include	<stdio.h>

int	main(void)
{
	char	str1[] = "aaaaa";
	char	str2[] = "bbb";
	char	*result = ft_strjoin(str1, str2);

	printf("%s\n", result);
	free(result);
}
*/
