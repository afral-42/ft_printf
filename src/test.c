/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 14:35:09 by abounoua          #+#    #+#             */
/*   Updated: 2025/11/14 14:57:30 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\f' || c == '\r' || c == '\v'
		|| c == '\n')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	while (ft_is_space(*nptr) && *nptr)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '+')
			sign = 1;
		else
			sign = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9' && (*nptr))
	{
		result *= 10;
		result += *nptr - '0';
		nptr++;
	}
	return (result * sign);
}


static t_params	*handle_args(const char *format)
{
	t_params	*params;

	params = malloc(sizeof(t_params));
	if (!params)
		return NULL;
	params->flags = 0;
	params->size = 0;
	if (*format == '-')
		params->flags |= FLAG_MINUS;
	else if (*format == '0')
		params->flags |= FLAG_ZERO;
	else
		params->flags = 0;
	params->size = ft_atoi(format + 1);
	return (params);
}

#include <stdio.h>
int	main(void)
{
	t_params	*test;

	test = handle_args("-123d");
	printf("%d\n%d\n", test->flags, test->size);
	free(test);
}
