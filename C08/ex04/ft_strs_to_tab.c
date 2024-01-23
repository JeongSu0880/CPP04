/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 09:15:54 by jungslee          #+#    #+#             */
/*   Updated: 2023/09/12 18:34:38 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	"ft_strs_to_tab.h"

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

char	*ft_strdup(char *src)
{
	char	*str;
	int		len;
	int		i;
	
	i = 0;
	len = ft_strlen(src);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (str ==NULL)
		return (0);
	while (src[i])
	{
		str[i] = sr[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

struct	s_stock_str *ft_strs_to_tab(int	ac, char **av)
{
	t_stock_str	*box;
	int	i;

	i = 0;
	box = (t_stock_str *)malloc(sizeof(t_stock_str) * ac);
	if (box == NULL)
		return (0);
	while (av[i])
	{
		box[i].size = ft_strlen(av[i]);
		box[i].str = av[i];
		box[i].copy = ft_strdup(av[i]);
		i++;
	}
	box[i].str = 0;
	return (box);
}
