/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 13:01:35 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/21 20:01:58 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_isprint(int c)
{
	if (32 <= c && c <= 126)
		return (1);
	else
		return (0);
}
/*
#include	<ctype.h>
#include	<stdio.h>

int	main(void)
{
	printf("%d\n", ft_isprint(31));
	printf("%d\n", isprint(31));
}
*/
