/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungslee <jungslee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:54:36 by jungslee          #+#    #+#             */
/*   Updated: 2023/12/05 15:21:35 by jungslee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include "./libft/libft.h"

int		ft_printf(const char *format, ...);
int		detect_type(va_list ap, char *letter);
char	*ft_itoa_hex(uintptr_t n);
char	*ft_itoa_u(unsigned int n);
char	*handle_c(va_list ap, int *c_flag);
char	*handle_s(va_list ap);
char	*handle_p(va_list ap);
char	*handle_id(va_list ap);
char	*handle_u(va_list ap);
char	*handle_x(va_list ap, char letter);
char	*handle_percent(char *percent);

#endif
