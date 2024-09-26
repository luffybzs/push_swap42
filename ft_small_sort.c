/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 12:12:55 by ayarab            #+#    #+#             */
/*   Updated: 2024/09/26 17:06:51 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int   is_sorted(t_lst *lsta, t_lst *lstb)
{
	t_node	*node;

	if (!lsta || !lsta->first)
		return (0);
	if (lstb && lstb->first)
		return (0);
	node = lsta->first;
	while (node->next)
	{
		if (node->content > node->next->content)
			return (0);
		node = node->next;
	}
	return (1);
}
void	ft_sort_2(t_lst *lsta, t_lst *lstb)
{
	t_node	*lst;

	lst = lsta->first;
	if (lst == NULL || lst->next == NULL)
		return ;
	if (is_sorted(lsta, lstb) == 0)
		ft_sa(lsta);
}

void	ft_3(t_lst *lsta)
{
	t_node	*low;
	t_node	*higher;
	int		lowest_ind;
	int		higher_index;

	low = search_low(lsta);
	higher = search_top(lsta);
	higher_index = ft_search_index(higher, lsta);
	if (higher_index == 0)
		ft_ra(lsta);
	else if (higher_index == 1)
		ft_rra(lsta);
	lowest_ind = ft_search_index(low, lsta);
	if (lowest_ind == 1)
		ft_sa(lsta);
}
t_node	*search_low(t_lst *lst)
{
	t_node	*current;
	t_node	*lowest;

	lowest = lst->first;
	if (lowest->next == NULL)
		return (lowest);
	current = lst->first->next;
	while (current)
	{
		if (current->content < lowest->content)
			lowest = current;
		current = current->next;
	}
	return (lowest);
}

t_node	*search_top(t_lst *lst)
{
	t_node	*current;
	t_node	*top;

	top = lst->first;
	current = lst->first->next;
	while (current)
	{
		if (current->content > top->content)
			top = current;
		current = current->next;
	}
	return (top);
}
