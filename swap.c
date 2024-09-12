/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:07:19 by ayarab            #+#    #+#             */
/*   Updated: 2024/09/12 15:17:31 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_lst *lst)
{
	int		tmp;
	t_node	*current;
	t_node	*second;

	current = lst->first;
	if(!current || ft_lstlen(lst) == 1)
		return ;
	second = current->next;
	tmp = current->content;
	current->content = second->content;
	second->content = tmp;
}
void	ft_sa(t_lst *lsta)
{
	swap(lsta);
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_lst *lstb)
{
	swap(lstb);
	ft_putstr_fd("sb\n", 1);
}
void	ft_ss(t_lst *lsta, t_lst *lstb)
{
	swap(lsta);
	swap(lstb);
	ft_putstr_fd("ss\n", 1);
}