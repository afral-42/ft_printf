/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:21:07 by abounoua          #+#    #+#             */
/*   Updated: 2025/11/20 16:26:21 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	pointer_len(uintptr_t adr)
{
	int	len;

	len = 0;
	while (adr)
	{
		adr /= 16;
		len++;
	}
	return (len);
}

static void	ft_putaddress(uintptr_t adr, int *count)
{
	const char	*base = "0123456789abcdef";

	if (adr >= 0 && adr <= 15)
		*count += ft_putchar_r(base[adr]);
	else
	{
		ft_putaddress(adr / 16, count);
		*count += ft_putchar_r(base[adr % 16]);
	}
}

int	ft_print_pointer(t_params *params, void *p)
{
	int	count;

	count = 0;
	if (!p)
		return (ft_print_null('p'));
	if (!(params->flags & FLAG_MINUS))	
		count += handle_space(params, pointer_len((uintptr_t)p) + 2);
	count += ft_putnstr("0x", 2);
	ft_putaddress((uintptr_t)p, &count);
	if (params->flags & FLAG_MINUS)
		count += handle_space(params, pointer_len((uintptr_t)p) + 2);
	return (count);
}
