/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:03:07 by abounoua          #+#    #+#             */
/*   Updated: 2025/11/20 20:07:50 by anselme          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_all(char **s, int *error)
{
	size_t	i;

	i = 0;
	while (s[i] != NULL)
	{
		free(s[i]);
		i++;
	}
	free(s);
	*error = -1;
	return (NULL);
}

static size_t	get_splitted_len(size_t *len, char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	is_new_word;

	i = 0;
	count = 0;
	is_new_word = 1;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			is_new_word = 1;
		else if (is_new_word)
		{
			count++;
			is_new_word = 0;
		}
		i++;
	}
	*len = count;
	return (count);
}

static char	*extract_word(char const *s, char c)
{
	size_t	len;
	char	*result;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	ft_strlcpy(result, s, len + 1);
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	size_t	j;
	char	**result;

	result = malloc((get_splitted_len(&j, s, c) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	result[j] = NULL;
	i = 0;
	j = 0;
	while (i != -1 && s[i] != '\0')
	{
		if (s[i] == c)
			i++;
		else
		{
			result[j] = extract_word(&(s[i]), c);
			if (!result[j])
				return (free_all(result, &i));
			j++;
			while (i != -1 && s[i] != '\0' && s[i] != c)
				i++;
		}
	}
	return (result);
}
