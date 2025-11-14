/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 18:21:07 by abounoua          #+#    #+#             */
/*   Updated: 2025/11/13 17:07:13 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putaddress(uintptr_t adr, int *count)
{
	const char	*base = "0123456789abcdef";

	if (adr >= 0 && adr <= 15)
		*count += ft_print_char(base[adr]);
	else
	{
		ft_putaddress(adr / 16, count);
		*count += ft_print_char(base[adr % 16]);
	}
}

int	ft_print_pointer(void *p)
{
	int	count;

	count = 0;
	if (!p)
		return (ft_print_null('p'));
	ft_print_str("0x");
	count += 2;
	ft_putaddress((uintptr_t)p, &count);
	return (count);
}
