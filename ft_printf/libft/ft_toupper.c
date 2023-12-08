/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:52:26 by jungslee          #+#    #+#             */
/*   Updated: 2023/10/21 20:55:29 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_toupper(int c)
{
	if (97 <= c && c <= 122)
		c -= 32;
	return (c);
}
/*
#include	<ctype.h>
#include	<stdio.h>

int main(void)
{
	printf("ft : %c\n", ft_toupper('a'));
	printf("original : %c\n", toupper('a'));
}
*/
