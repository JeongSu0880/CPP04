/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:37:33 by jungslee          #+#    #+#             */
/*   Updated: 2023/09/11 12:11:51 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		write(1, &argv[0][i], 1);
		i++;
	}
}