/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 08:32:11 by abounoua          #+#    #+#             */
/*   Updated: 2025/11/14 11:23:32 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(int nb, int *count)
{
	if (nb < 0)
	{
		if (nb == -2147483648)
		{
			*count = write(1, "-2147483648", 11);
			return ;
		}
		nb = -nb;
		*count += ft_print_char('-');
	}
	if (nb >= 0 && nb <= 9)
		*count += ft_print_char('0' + nb);
	else
	{
		ft_putnbr(nb / 10, count);
		*count += ft_print_char('0' + nb % 10);
	}
}

int	ft_print_nbr(int nb)
{
	int	count;

	count = 0;
	ft_putnbr(nb, &count);
	return (count);
}
