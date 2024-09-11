/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:29:10 by ayarab            #+#    #+#             */
/*   Updated: 2024/09/11 18:27:22 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back_stack(t_node *lst, t_node *new)
{
	t_node *temp;

	if (!lst)
	{
		lst = new;
		return ;
	}
	temp = lst;
	while (temp->next)
	{
		temp = temp->next;
	}
	temp->next = new;
}
