/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:52:52 by ayarab            #+#    #+#             */
/*   Updated: 2024/09/26 17:06:57 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_stack(t_stack *both, int len, int *tab)
{
	ft_first_half(both, len, tab);
	ft_last_half(both, len, tab);
	ft_3(&both->lsta);
	while (both->lstb.first != NULL)
	{
		ft_cost_all(&both->lsta, &both->lstb);
		ft_insert(both);
	}
	ft_sort(both);
}
void	ft_first_half(t_stack *both, int len, int *tab)
{
	t_lst	*stack;

	stack = &both->lsta;
	while (ft_lstlen(stack) > len / 2 + 1)
	{
		if (stack->first->content > tab[len / 4 * 3])
		{
			ft_pb(&both->lsta, &both->lstb);
			if (stack->first->content <= len / 2)
				ft_rr(&both->lsta, &both->lstb);
			else
				ft_rb(&both->lstb);
		}
		else if (stack->first->content > tab[len * 1 / 2])
		{
			ft_pb(&both->lsta, &both->lstb);
		}
		else
		{
			ft_ra(&both->lsta);
		}
	}
}
void	ft_last_half(t_stack *both, int len, int *tab)
{
	t_lst	*stack;
	int		number_input;

	stack = &both->lsta;
	number_input = len;
	while (ft_lstlen(stack) > 3)
	{
		if (stack->first->content > tab[number_input / 4])
			ft_pb(&both->lsta, &both->lstb);
		else
		{
			ft_pb(&both->lsta, &both->lstb);
			ft_rb(&both->lstb);
		}
	}
}
void	ft_sort(t_stack *both)
{
	t_node		*lower;

	lower = search_low(&both->lsta);
	ft_rotate_top(lower, &both->lsta, both);
}