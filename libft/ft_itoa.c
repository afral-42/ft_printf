/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:56:56 by abounoua          #+#    #+#             */
/*   Updated: 2025/11/17 14:59:26 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_array_len(size_t *final_index, int nb)
{
	int	len;

	len = 0;
	if (nb < 0)
		len++;
	while (nb)
	{
		nb /= 10;
		len++;
	}
	*final_index = len;
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	temp;
	size_t	index;

	if (!n)
		return (ft_strdup("0"));
	temp = (long)n;
	result = malloc(sizeof(char) * (get_array_len(&index, n)) + 1);
	if (!result)
		return (NULL);
	result[index] = '\0';
	index--;
	if (n < 0)
	{
		temp = -temp;
		result[0] = '-';
	}
	while (temp)
	{
		result[index] = temp % 10 + '0';
		index--;
		temp /= 10;
	}
	return (result);
}
