/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:08:30 by ayarab            #+#    #+#             */
/*   Updated: 2024/09/26 18:39:51 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_lst *lsta, t_lst *lstb)
{
	t_node	*current;

	if (lsta->first == NULL)
		return ;
	current = lsta->first;
	lsta->first = current->next;
	current->next = lstb->first;
	lstb->first = current;
}

void	ft_pb(t_lst *lsta, t_lst *lstb)
{
	ft_push(lsta, lstb);
	ft_putstr_fd("pb\n", 1);
}

void	ft_pa(t_lst *lsta, t_lst *lstb)
{
	ft_push(lstb, lsta);
	ft_putstr_fd("pa\n", 1);
}
