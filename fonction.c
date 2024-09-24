/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:38:24 by ayarab            #+#    #+#             */
/*   Updated: 2024/09/23 17:39:20 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_target(t_lst *lsta, t_node *node)
{
	t_node	*current;
	int		res;

	current = lsta->first;
	node->target = NULL;
	while (current != NULL)
	{
		if (current->content > node->content)
		{
			res = current->content - node->content;
			if (node->target == NULL || res < node->target->content
				- node->content)
				node->target = current;
		}
		current = current->next;
	}
	if (node->target == NULL)
		node->target = search_low(lsta);
}
int	ft_search_index(t_node *node, t_lst *lst)
{
	t_node	*current;
	int		i;

	current = lst->first;
	i = 0;
	while (current)
	{
		if (current == node)
			return (i);
		current = current->next;
		i++;
	}
	return (-1);
}