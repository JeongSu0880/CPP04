/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:06:59 by jungslee          #+#    #+#             */
/*   Updated: 2023/09/13 16:55:51 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (0);
}

int	all_length(char *str, char **strs, int size, char *sep)
{
	int	i;
	int	j;
	int	length;

	i = 0;
	length = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			j++;
		}
		if (i == size - 1)
			length = length + j;
		else
			length = length + j + ft_strlen(sep);
		i++;
	}
	return (length);
}

void putstrs(char **strs, char *str, int size, char *sep)
{
	int	i;
	int	j;
	int	r;
	int s;

	i = 0;
	r = 0;
	while (r < size)
	{
		j = 0;
		while (strs[r][j])
		{
			str[i] = strs[r][j];
			j++;
			i++;
		}
		s = 0;
		while (sep[s] && r != size - 1)
		{
			str[i] = sep[s];
			s++;
			i++;
		}
		r++;
	}
	str[i] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		length;
	char	*str;

	i = 0;
	length = all_length(str, strs, size, sep);
	str = (char *)malloc(sizeof(char) * length + 1);
	if (size == 0)
		return (str);
	putstrs(strs, str, size, sep);
	return (str);
}

#include	<unistd.h>

int main()
{
	char *str;
	char *strs[5] = {"cat", "dog", "parrot", "jjangjjang", "segal"};

	str = ft_strjoin(5, strs, ",");
	write(1, str, 31);
}

