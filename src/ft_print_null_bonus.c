/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_null_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:15:44 by abounoua          #+#    #+#             */
/*   Updated: 2025/11/20 14:08:47 by abounoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_print_null(char format)
{
	if (format == 's')
	{
		ft_putnstr("(null)", 6);
		return (6);
	}
	else
	{
		ft_putnstr("(nil)", 5);
		return (5);
	}
}
