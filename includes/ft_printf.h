/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:09:57 by abounoua          #+#    #+#             */
/*   Updated: 2025/11/14 09:54:41 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h> 
# include <unistd.h>
# include <stdarg.h>

int		ft_print_char(char c);
int		ft_print_str(char *str);
int		ft_print_pointer(void *p);
int		ft_print_nbr(int nb);
int		ft_print_unsigned(unsigned int nb);
int		ft_print_null(char format);
int		ft_print_hex(unsigned int nb, int maj);
int		ft_printf(const char *format, ...);

#endif
