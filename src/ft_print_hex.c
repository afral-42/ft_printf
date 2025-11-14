/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:07:46 by abounoua          #+#    #+#             */
/*   Updated: 2025/11/14 11:19:15 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_puthex(unsigned int nb, int *count, char *base)
{
	if (nb >= 0 && nb <= 15)
		*count += ft_print_char(base[nb]);
	else
	{
		ft_puthex(nb / 16, count, base);
		*count += ft_print_char(base[nb % 16]);
	}
}

int	ft_print_hex(unsigned int nb, int maj)
{
	int		count;
	char	*base;

	count = 0;
	if (!maj)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	ft_puthex(nb, &count, base);
	return (count);
}
