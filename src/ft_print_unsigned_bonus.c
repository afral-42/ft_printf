/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:29:01 by abounoua          #+#    #+#             */
/*   Updated: 2025/11/20 16:27:08 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	nbr_len(unsigned int nb)
{
	int	len;

	if (!nb)
		return (1);
	len = 0;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

static void	ft_putunsigned(unsigned int nb, int *count)
{
	if (nb >= 0 && nb <= 9)
		*count += ft_putchar_r('0' + nb);
	else
	{
		ft_putunsigned(nb / 10, count);
		*count += ft_putchar_r('0' + nb % 10);
	}
}

int	ft_print_unsigned(t_params *params, unsigned int nb)
{
	int				count;
	unsigned int	zeros;
	unsigned int	nlen;

	zeros = 0;
	nlen = nbr_len(nb);
	if (params->precision > (int)nlen)
		zeros = params->precision - nlen;
	count = 0;
	if (!(params->flags & FLAG_MINUS))
		count += handle_space(params, nlen + zeros);
	count += fill_space(zeros, '0');
	ft_putunsigned(nb, &count);
	if (params->flags & FLAG_MINUS)
		count += handle_space(params, nbr_len(nb));
	return (count);
}
