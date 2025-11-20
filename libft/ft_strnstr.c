/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 19:41:34 by abounoua          #+#    #+#             */
/*   Updated: 2025/11/10 12:10:35 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *)big);
	if (!len)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len && big[i] != '\0')
	{
		while (big[i + j] == little[j] && little[j]
			&& big[i + j] && i + j < len)
			j++;
		if (little[j] == '\0')
			return ((char *)(&(big[i])));
		else
		{
			j = 0;
			i++;
		}
	}
	return (NULL);
}
