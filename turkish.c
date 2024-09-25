/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 11:47:08 by ayarab            #+#    #+#             */
/*   Updated: 2024/09/25 14:31:18 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_find_lower_price(t_lst *stack)
{
	t_node	*current;
	t_node	*lowest;

	lowest = stack->first;
	current = stack->first->next;
	while (current)
	{
		if (current->cost < lowest->cost)
			lowest = current;
		current = current->next;
	}
	return (lowest);
}
void	ft_insert(t_stack *stack)
{
	t_node	*change;
	t_node	*closest;

	change = ft_find_lower_price(&stack->lstb);
	closest = change->target;
	ft_rotate_top(change, &stack->lstb, stack);
	ft_rotate_top(closest, &stack->lsta, stack);
	ft_pa(&stack->lsta, &stack->lstb);
}

void	ft_rotate_top(t_node *node, t_lst *stack, t_stack *both)
{
	if (ft_search_index(node, stack) > (ft_lstlen(stack) / 2))
	{
		while (stack->first != node)
		{
			if (stack == &both->lstb)
				ft_rrb(&both->lstb);
			else
				ft_rra(&both->lsta);
		}
	}
	else
	{
		while (stack->first != node)
		{
			if (stack == &both->lstb)
				ft_rb(&both->lstb);
			else
				ft_ra(&both->lsta);
		}
	}
}
t_node	*ft_lower_price(t_lst *stack)
{
	t_node	*current;
	t_node	*cheapest;

	current = stack->first;
	cheapest = stack->first;
	while (current != NULL)
	{
		if (current->cost < cheapest->cost)
			cheapest = current;
		current = current->next;
	}
	return (cheapest);
}
