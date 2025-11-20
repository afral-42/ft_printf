/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:09:57 by abounoua          #+#    #+#             */
/*   Updated: 2025/11/20 14:19:08 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdint.h>
# include <unistd.h>
# include <stdarg.h>
# include "parser_bonus.h"

unsigned int	min(unsigned int a, unsigned int b);
int				ft_print_char(t_params *params, char c);
int				ft_print_str(t_params *params, char *str);
int				ft_print_pointer(t_params *params, void *p);
int				ft_print_nbr(t_params *params, int nb);
int				ft_print_unsigned(t_params *params, unsigned int nb);
int				ft_print_null(char format);
int				ft_print_hex(t_params *params, unsigned int nb, int maj);
int				ft_printf(const char *format, ...);
int				ft_putnstr(char *str, unsigned int size);
int				ft_putchar_r(char c);

#endif
