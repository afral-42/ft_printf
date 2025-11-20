/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:15:39 by abounoua          #+#    #+#             */
/*   Updated: 2025/11/20 14:19:20 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_BONUS_H
# define PARSER_BONUS_H

typedef enum e_flags
{
	FLAG_MINUS = 1,
	FLAG_ZERO = 1 << 1,
	FLAG_PRECISION = 1 << 2
}	t_flags;

typedef struct s_params
{
	unsigned int	flags;
	unsigned int	width;
	int				precision;
	char			specifier;
}					t_params;

int	handle_args(const char **format, va_list args);
int	handle_format(t_params *params, va_list args);
int	ft_atoi(const char *nptr);
int	fill_space(unsigned int width, char c);
int	handle_space(t_params *params, unsigned int size);

#endif
