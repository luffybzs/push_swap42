/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 16:38:24 by ayarab            #+#    #+#             */
/*   Updated: 2024/09/26 18:34:58 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_find_target(t_lst *lsta, t_node *node)
{
	t_node		*current;
	t_node		*target;
	long long	min_diff;
	long long	diff;

	current = lsta->first;
	target = NULL;
	min_diff = LLONG_MAX;
	while (current != NULL)
	{
		if (current->content > node->content)
		{
			diff = (long long)current->content - node->content;
			if (diff < min_diff)
			{
				min_diff = diff;
				target = current;
			}
		}
		current = current->next;
	}
	if (!target)
		target = search_low(lsta);
	node->target = target;
}

int	ft_search_index(t_node *node, t_lst *lst)
{
	int		i;
	t_node	*current;

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
