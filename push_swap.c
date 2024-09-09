/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:36:07 by ayarab            #+#    #+#             */
/*   Updated: 2024/09/09 17:07:26 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_free_list(t_lst *lst)
{
	//t_lst *first;
	t_node *current;
	t_node *ptr;
	
	current = lst->first;
	while (current)
	{
		ptr = current->next;
		free(current);
		current = ptr;
	}
	free(lst);
}
void	display_stack(t_lst *lst)
{
	t_node	*current;

	current = lst->first;
	while (current)
	{
		printf("[%d]\n", current->content);
		current = current->next;
	}
}

int	main(int ac, char **av)
{
	int *tab;
	t_lst *lst;
	int i;

	lst = ft_init_stack(); 
	if (!lst)
		return (0);
	tab = ft_valid(ac, av, lst);
	if (!tab)
		return (0);
	i = 0;
	while (i < lst->len)
		add_to_queue(lst, tab[i++]);
	free(tab);
	display_stack(lst);
	ft_free_list(lst);
	return (0);
}