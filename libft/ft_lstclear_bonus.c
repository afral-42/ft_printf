/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abounoua <abounoua@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 16:56:12 by abounoua          #+#    #+#             */
/*   Updated: 2025/11/07 17:08:14 by abounoua         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;
	t_list	*temp;

	if (!lst || !del || !(*lst))
		return ;
	node = *lst;
	while (node != NULL)
	{
		temp = node->next;
		(*del)(node->content);
		free(node);
		node = temp;
	}
	*lst = NULL;
}
