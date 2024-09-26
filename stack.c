/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utilisateur <utilisateur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:48:11 by ayarab            #+#    #+#             */
/*   Updated: 2024/09/25 21:35:09 by utilisateur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_queue(t_lst *lst, int nbr)
{
	t_node	*new;
	t_node	*current;

	new = malloc(sizeof(t_node));
	if (!new)
		return ;
	new->next = NULL;
	new->content = nbr;
	new->target = NULL;
	if (!lst->first)
		lst->first = new;
	else
	{
		current = lst->first;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

t_lst	*ft_init_stack(void)
{
	t_lst	*new;

	new = malloc(sizeof(t_lst));
	if (!new)
		return (NULL);
	else
		new->first = NULL;
	return (new);
}
