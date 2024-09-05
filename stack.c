/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 17:48:11 by ayarab            #+#    #+#             */
/*   Updated: 2024/09/05 18:34:47 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	init_stack(int *tab, int size)
{
	int i;
	t_stack *stack;
	t_list *current;
	
	i = 0;
	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	current = ft_lstnew(tab[i++]);
	stack->first = current;
	while (i < size)
	{
		current->next = ft_lstnew(tab[i]);
		current->next->prev = current;
		current = current->next;
		i++;
	}
	return (stack);
}