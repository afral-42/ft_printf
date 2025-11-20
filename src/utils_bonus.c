/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 10:37:21 by abounoua          #+#    #+#             */
/*   Updated: 2025/11/20 14:12:09 by abounoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include "parser_bonus.h"

unsigned int	min(unsigned int a, unsigned int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

int	fill_space(unsigned int width, char c)
{
	unsigned int	i;

	i = 0;
	while (i < width)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

int	handle_space(t_params *params, unsigned int size)
{
	int	count;

	if (size >= params->width)
		return (0);
	count = 0;
	if (!(params->width))
		return (0);
	if (params->flags & FLAG_ZERO)
		count += fill_space(params->width - size, '0');
	else if (params->flags & FLAG_MINUS || params->width)
		count += fill_space(params->width - size, ' ');
	return (count);
}
