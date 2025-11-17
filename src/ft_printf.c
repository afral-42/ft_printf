/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:13:44 by abounoua          #+#    #+#             */
/*   Updated: 2025/11/17 16:01:52 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(char format, va_list args)
{
	if ('c' == format)
		return (ft_print_char(va_arg(args, int)));
	else if ('s' == format)
		return (ft_print_str(va_arg(args, char *)));
	else if ('p' == format)
		return (ft_print_pointer(va_arg(args, void *)));
	else if ('d' == format || 'i' == format)
		return (ft_print_nbr(va_arg(args, int)));
	else if ('u' == format)
		return (ft_print_unsigned(va_arg(args, unsigned int)));
	else if ('x' == format)
		return (ft_print_hex(va_arg(args, unsigned int), 0));
	else if ('X' == format)
		return (ft_print_hex(va_arg(args, unsigned int), 1));
	else if ('%' == format)
		return (ft_print_char('%'));
	return (ft_print_char(format));
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
			printed_count += handle_format(*format, args);
		}
		else
			printed_count += ft_print_char(*format);
		format++;
	}
	va_end(args);
	return (printed_count);
}
