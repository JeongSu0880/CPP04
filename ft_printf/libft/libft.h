/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:24:15 by jungslee          #+#    #+#             */
/*   Updated: 2023/12/04 16:23:38 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memmove(void *dest, const void *src, size_t num);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_toupper(int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_itoa(int n);

#endif
