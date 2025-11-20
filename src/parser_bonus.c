/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:35:09 by abounoua          #+#    #+#             */
/*   Updated: 2025/11/20 14:48:40 by abounoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "parser_bonus.h"
#include "libft.h"

static void	parse_flags(const char **format, t_params *params)
{
	while (**format != '\0')
	{
		if (**format == '-')
			params->flags |= FLAG_MINUS;
		else if (**format == '0')
			params->flags |= FLAG_ZERO;
		else
			break ;
		(*format)++;
	}
	if (params->flags & FLAG_MINUS)
		params->flags = params->flags & ~FLAG_ZERO;
}

static void	parse_width(const char **format, t_params *params)
{
	if (**format >= '0' && **format <= '9')
	{
		params->width = ft_atoi(*format);
		while (**format && **format >= '0' && **format <= '9')
			(*format)++;
	}
}

static void	parse_precision(const char **format, t_params *params)
{
	if (**format == '.')
	{
		(*format)++;
		params->precision = ft_atoi(*format);
		while (**format && **format >= '0' && **format <= '9')
			(*format)++;
	}
	else
		params->precision = -1;
}

static void	parse_specifier(const char **format, t_params *params)
{
	char	c;

	c = (char)(**format);
	if (c == 'u' || c == 's' || c == 'c' || c == 'x' || c == 'p'
		|| c == 'X' || c == 'd' || c == 'i' || c == '%')
	{
		params->specifier = c;
		(*format)++;
	}
	else
		params->specifier = 0;
}

int	handle_args(const char **format, va_list args)
{
	t_params	params;
	int			result;

	params.flags = 0;
	params.width = 0;
	params.precision = -1;
	params.specifier = 0;
	parse_flags(format, &params);
	parse_width(format, &params);
	parse_precision(format, &params);
	parse_specifier(format, &params);
	result = handle_format(&params, args);
	return (result);
}
