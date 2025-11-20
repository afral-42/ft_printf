/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 08:32:11 by abounoua          #+#    #+#             */
/*   Updated: 2025/11/20 14:08:40 by abounoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

static unsigned int	nbr_len(int nb)
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

static void	ft_putnbr(long nb, int *count)
{
	if (nb >= 0 && nb <= 9)
		*count += ft_putchar_r('0' + nb);
	else
	{
		ft_putnbr(nb / 10, count);
		*count += ft_putchar_r('0' + nb % 10);
	}
}

int	print_minus(long *temp)
{
	*temp = -(*temp);
	return (write(1, "-", 1));
}

int	ft_print_nbr(t_params *params, int nb)
{
	int					count;
	unsigned int		nlen;
	unsigned int		zeros;
	long				temp;

	temp = (long)nb;
	count = 0;
	nlen = nbr_len(nb);
	if (params->precision > (int)nlen)
		zeros = params->precision - nlen;
	else if (nb == 0 && params->precision == 0)
		return (0);
	else
		zeros = 0;
	if (nb < 0)
		count += print_minus(&temp);
	if (!(params->flags & FLAG_MINUS))
		count += handle_space(params, nlen + zeros + (nb < 0));
	count += fill_space(zeros, '0');
	ft_putnbr(temp, &count);
	if (params->flags & FLAG_MINUS)
		count += handle_space(params, nlen + zeros + (nb < 0));
	return (count);
}
