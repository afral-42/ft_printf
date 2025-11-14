/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 15:29:01 by abounoua          #+#    #+#             */
/*   Updated: 2025/11/13 16:18:37 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putunsigned(unsigned int nb, int *count)
{
	if (nb >= 0 && nb <= 9)
		*count += ft_print_char('0' + nb);
	else
	{
		ft_putunsigned(nb / 10, count);
		*count += ft_print_char('0' + nb % 10);
	}
}

int	ft_print_unsigned(unsigned int nb)
{
	int	count;

	count = 0;
	ft_putunsigned(nb, &count);
	return (count);
}
