/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:13:44 by abounoua          #+#    #+#             */
/*   Updated: 2025/11/20 14:09:21 by abounoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "parser_bonus.h"

int	handle_format(t_params *params, va_list args)
{
	if ('c' == params->specifier)
		return (ft_print_char(params, va_arg(args, int)));
	else if ('s' == params->specifier)
		return (ft_print_str(params, va_arg(args, char *)));
	else if ('p' == params->specifier)
		return (ft_print_pointer(params, va_arg(args, void *)));
	else if ('d' == params->specifier || 'i' == params->specifier)
		return (ft_print_nbr(params, va_arg(args, int)));
	else if ('u' == params->specifier)
		return (ft_print_unsigned(params, va_arg(args, unsigned int)));
	else if ('x' == params->specifier)
		return (ft_print_hex(params, va_arg(args, unsigned int), 0));
	else if ('X' == params->specifier)
		return (ft_print_hex(params, va_arg(args, unsigned int), 1));
	else if ('%' == params->specifier)
		return (write(1, &(params->specifier), 1));
	return (write(1, &(params->specifier), 1));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed_count;

	va_start(args, format);
	printed_count = 0;
	while ('\0' != *format)
	{
		if (*format == '%')
		{
			format++;
			if (!(*format))
				return (-1);
			printed_count += handle_args(&format, args);
		}
		else
		{
			printed_count += write(1, format, 1);
			format++;
		}
	}
	va_end(args);
	return (printed_count);
}
