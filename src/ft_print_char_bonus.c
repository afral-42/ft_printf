/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:04:09 by abounoua          #+#    #+#             */
/*   Updated: 2025/11/20 16:25:30 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 
#include "parser_bonus.h"

int	ft_print_char(t_params *params, char c)
{
	int	count;

	count = 0;
	if (params->flags & FLAG_MINUS)
	{
		count += write(1, &c, 1);
		count += handle_space(params, 1);
		return (count);
	}
	else
		count += handle_space(params, 1);
	count += write(1, &c, 1);
	return (count);
}
