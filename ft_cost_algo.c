/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cost_algo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:31:58 by ayarab            #+#    #+#             */
/*   Updated: 2024/09/26 18:36:56 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cost_all(t_lst *lsta, t_lst *lstb)
{
	t_node	*lst;

	lst = lstb->first;
	while (lst != NULL)
	{
		lst->cost = ft_cost(lst, lsta, lstb);
		lst = lst->next;
	}
}

int	ft_cost(t_node *lst, t_lst *lsta, t_lst *lstb)
{
	int	cost;

	cost = ft_cost_top(lst, lstb);
	ft_find_target(lsta, lst);
	cost += ft_cost_top(lst->target, lsta);
	++cost;
	return (cost);
}

int	ft_cost_top(t_node *lst, t_lst *stack)
{
	t_node	*current;
	int		index;
	int		cost;

	cost = 0;
	current = lst;
	index = ft_search_index(lst, stack);
	if (index > ft_lstlen(stack) / 2)
	{
		while (current->next)
		{
			current = current->next;
			cost++;
		}
		cost++;
	}
	else
		cost = index;
	return (cost);
}

t_node	*ft_highest(t_node *lst, t_lst *stack)
{
	int		temp;
	t_node	*current;
	t_node	*closest;

	current = stack->first;
	closest = stack->first;
	temp = 2147483647;
	while (current != NULL)
	{
		if (current->content < temp && lst->content < current->content)
		{
			closest = current;
			temp = current->content;
		}
		current = current->next;
	}
	return (closest);
}
