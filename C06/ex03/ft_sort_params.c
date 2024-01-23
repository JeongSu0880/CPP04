/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:38:06 by jungslee          #+#    #+#             */
/*   Updated: 2023/09/11 12:00:12 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

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

void	print(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			write(1, &argv[i][j], 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int		i;
	int		j;
	char	*key;

	i = 1;
	while (i < argc)
	{
		key = argv[i];
		j = i - 1;
		while (j > 0 && (ft_strcmp(key, argv[j]) < 0))
		{
			argv[j + 1] = argv[j];
			j--;
		}
		argv[j + 1] = key;
		i++;
	}
	print(argc, argv);
}
