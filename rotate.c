/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:08:33 by ayarab            #+#    #+#             */
/*   Updated: 2024/09/11 19:27:09 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_last(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	rotate(t_lst *lst)
{
	t_node	*first;
	t_node	*last;

	if (!lst->first || !lst->first->next)
		return ;
	first = lst->first;
	lst->first = first->next;
	last = ft_last(lst->first);
	last->next = first;
	first->next = NULL;
}

void	ft_ra(t_lst *lst)
{
	rotate(lst);
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_lst *lst)
{
	rotate(lst);
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_lst *lsta, t_lst *lstb)
{
	rotate(lsta);
	rotate(lstb);
	ft_putstr_fd("rr\n", 1);
}