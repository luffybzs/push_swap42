/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:08:27 by ayarab            #+#    #+#             */
/*   Updated: 2024/09/26 18:40:15 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_lst *stack)
{
	t_node	*last;
	t_node	*second_last;

	if (!(stack->first) || !(stack->first->next))
		return ;
	second_last = ft_second_last(stack->first);
	last = second_last->next;
	last->next = stack->first;
	stack->first = last;
	second_last->next = NULL;
}

void	ft_rra(t_lst *lsta)
{
	if (!(lsta->first) || !(lsta->first->next))
		return ;
	reverse_rotate(lsta);
	ft_putendl_fd("rra", 1);
}

void	ft_rrb(t_lst *lstb)
{
	if (!(lstb->first) || !(lstb->first->next))
		return ;
	reverse_rotate(lstb);
	ft_putendl_fd("rrb", 1);
}

void	ft_rrr(t_lst *lsta, t_lst *lstb)
{
	if (!(lsta->first) || !(lsta->first->next) || !(lstb->first)
		|| !(lstb->first->next))
		return ;
	reverse_rotate(lsta);
	reverse_rotate(lstb);
	ft_putendl_fd("rrr", 1);
}

t_node	*ft_second_last(t_node *lst)
{
	if (!lst || !lst->next)
		return (NULL);
	while (lst->next->next)
		lst = lst->next;
	return (lst);
}
