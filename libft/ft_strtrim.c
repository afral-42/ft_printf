/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:59:47 by abounoua          #+#    #+#             */
/*   Updated: 2025/11/11 14:01:42 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	get_trimmed_size(char const *s1, char const *set, size_t *index)
{
	size_t	total_len;
	size_t	len_before;
	size_t	len_after;

	total_len = ft_strlen(s1);
	len_before = 0;
	while (s1[len_before] != '\0' && is_in_set(set, s1[len_before]))
		len_before++;
	*index = len_before;
	len_after = 0;
	while (is_in_set(set, s1[total_len - 1 - len_after])
		&& len_after != total_len)
		len_after++;
	if (len_before == total_len || len_after == total_len)
		return (0);
	return (total_len - (len_before + len_after));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;
	size_t	index;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	len = get_trimmed_size(s1, set, &index);
	if (!len)
		return (ft_strdup(""));
	result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = s1[index + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
