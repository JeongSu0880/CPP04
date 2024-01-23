/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:17:07 by jungslee          #+#    #+#             */
/*   Updated: 2023/09/02 15:27:42 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <unistd.h>

int	main(int argc, char **argv)
{
	int	complete[6][6];
	int	max_cnt;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < argc)
	{
		if ((sizeof(argv[i]) > 1 || ((argv[i][0] - '0') < 48)) 
				&& ((argv[i][0] - '0') > 57))
			write(1, "Input is not num", 16);
		if (i < 4)
			complete[0][i + 1] = argv[i][0];
		else if (i < 8)
			complete[5][i - 3] = argv[i][0];
		else if (i < 12)
			complete[i - 7][0] = argv[i][0];
		else if (i < 16)
			complete[i - 11][0] = argv[i][0];
		else
			write(1, "Too many inputs", 15);
	}
}
