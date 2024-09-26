/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utilisateur <utilisateur@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:08:27 by ayarab            #+#    #+#             */
/*   Updated: 2024/09/25 22:37:44 by utilisateur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// t_node	ft_second_last(t_node *lst)
// {
// 	if (!lst)
// 		return (NULL);
// 	while (lst->next->next)
// 		lst = lst->next;
// 	return (lst);
// }

// void	reverse_rotate(t_lst *lst)
// {
// 	t_lst	*last;
// 	t_lst	*second_last;

// 	if (!(lst->first) || !(lst->first->next))
// 		return ;
// 	second_last = ft_second_last(lst->first);
// 	last = second_last->next;
// 	last->next = lst->first;
// 	lst->first = last;
// 	second_last->next = NULL;
// }
// void	ft_rra(t_lst *lst)
// {
// 	reverse_rotate(lst);
// 	ft_putstr_fd("rra\n", 1);
// }

// void	ft_rrb(t_lst *lst)
// {
// 	reverse_rotate(lst);
// 	ft_putstr_fd("rrb\n", 1);
// }

// void	ft_rrr(t_lst *lsta, t_lst *lstb)
// {
// 	reverse_rotate(lsta);
// 	reverse_rotate(lstb);
// 	ft_putstr_fd("rrr\n", 1);
// }
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
	if (!(lsta->first) || !(lsta->first->next) || !(lstb->first) || !(lstb->first->next))
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