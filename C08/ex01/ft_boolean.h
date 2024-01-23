/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 04:49:02 by jungslee          #+#    #+#             */
/*   Updated: 2023/09/12 19:04:23 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_BOOLEAN_H
# define	FT_BOOLEAN_H
# include	<unistd.h>

typedef		int			t_bool;	
# define	TRUE		1
# define	FALSE		0
# define	EVEN(n)		(n % 2 == 0)
# define	EVEN_MSG	"I have an even number of arguments.\n"
# define	ODD_MSG		"I have an odd number of arguments.\n"
# define	SUCCESS		0


#endif
