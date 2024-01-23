/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:15:56 by jungslee          #+#    #+#             */
/*   Updated: 2023/09/12 12:44:34 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>
#include	"ft_stock_str.h"

void	ft_show_tab(struct s_stock_str *par)
{
	int	i;
	int	j;

	i = 0;
	while (par[i])
	{
		j = 0;
		while (par[i].str[j])
		{
			write(1, &par[i].str[j], 1);
			j++;
		}
		write(1, "\n", 1);
		write(1, &(par[i].size -+ '0'), 1);
		write(1, "\n", 1);
		j = 0;
		while (par[i].copy[j])
		{
			write(1, &par[i].str[j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
