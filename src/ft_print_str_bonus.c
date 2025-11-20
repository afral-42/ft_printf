/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:04:25 by abounoua          #+#    #+#             */
/*   Updated: 2025/11/20 16:25:59 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 
#include "parser_bonus.h"
#include "libft.h"

int	ft_putnstr(char *str, unsigned int size)
{
	return (write(1, str, size));
}

int	ft_print_str(t_params *params, char *str)
{
	int				count;
	unsigned int	size;

	if (!str)
		return (ft_print_null('s'));
	if (params->precision >= 0)
		size = min(ft_strlen(str), params->precision);
	else
		size = ft_strlen(str);
	count = 0;
	if (!(params->flags & FLAG_MINUS))
		count += handle_space(params, size);
	count += ft_putnstr(str, size);
	if (params->flags & FLAG_MINUS)
		count += handle_space(params, size);
	return (count);
}
