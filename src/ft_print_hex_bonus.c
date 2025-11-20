/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 17:07:46 by abounoua          #+#    #+#             */
/*   Updated: 2025/11/20 14:08:36 by abounoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static unsigned int	hex_len(unsigned int nb)
{
	int	len;

	if (!nb)
		return (1);
	len = 0;
	while (nb)
	{
		nb /= 16;
		len++;
	}
	return (len);
}

int	ft_putchar_r(char c)
{
	return (write(1, &c, 1));
}

static void	ft_puthex(unsigned int nb, int *count, char *base)
{
	if (nb >= 0 && nb <= 15)
		*count += ft_putchar_r(base[nb]);
	else
	{
		ft_puthex(nb / 16, count, base);
		*count += ft_putchar_r(base[nb % 16]);
	}
}

int	ft_print_hex(t_params *params, unsigned int nb, int maj)
{
	int		count;
	int		nlen;
	int		zeros;
	char	*base;

	count = 0;
	nlen = hex_len(nb);
	if (nb == 0 && params->precision == 0)
		nlen = 0;
	if (params->precision > nlen)
		zeros = params->precision - nlen;
	else
		zeros = 0;
	if (!maj)
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (!(params->flags & FLAG_MINUS))
		count += handle_space(params, nlen + zeros);
	count += fill_space(zeros, '0');
	ft_puthex(nb, &count, base);
	if (params->flags & FLAG_MINUS)
		count += handle_space(params, nlen + zeros);
	return (count);
}
