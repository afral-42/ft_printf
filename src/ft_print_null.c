/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_null.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:15:44 by abounoua          #+#    #+#             */
/*   Updated: 2025/11/13 16:31:20 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_null(char format)
{
	if (format == 's')
	{
		ft_print_str("(null)");
		return (6);
	}
	else
	{
		ft_print_str("(nil)");
		return (5);
	}
}
