/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:36:07 by ayarab            #+#    #+#             */
/*   Updated: 2024/09/25 17:27:31 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
void	ft_free_end(int *tab, t_lst *lsta, t_lst *lstb)
{
	free(tab);
	ft_free_list(lstb);
	ft_free_list(lsta);
}

void	ft_free_list(t_lst *lst)
{
	t_node	*current;
	t_node	*ptr;

	current = lst->first;
	while (current)
	{
		ptr = current->next;
		free(current);
		current = ptr;
	}
}
void	display_stack(t_lst *lst)
{
	t_node	*current;

	current = lst->first;
	if (current == NULL)
	{
		printf("la liste est vide\n");
		return ;
	}
	while (current)
	{
		printf("[%d]\n", current->content);
		current = current->next;
	}
}

int	main(int ac, char **av)
{
	int		*tab;
	int		i;
	t_stack	stack;

	i = 0;
	stack.lsta.first = NULL;
	stack.lstb.first = NULL;
	tab = ft_valid(ac, av, &stack.lsta);
	if (!tab)
		return (0);
	while (i < stack.lsta.len)
		add_to_queue(&stack.lsta, tab[i++]);
	if (is_sorted(&stack.lsta, &stack.lstb) == 1)
		return (ft_free_end(tab,&stack.lsta,&stack.lstb), 0);
	if (stack.lsta.len == 2)
	{
		ft_sort_for_2(&stack.lsta, &stack.lstb);
		return (ft_free_end(tab,&stack.lsta,&stack.lstb), 0);
	}
	else if (stack.lsta.len == 3)
		return (ft_sort_for_3(&stack.lsta), ft_free_end(tab,&stack.lsta,&stack.lstb), 0);
	if (stack.lsta.len > 3)
	{
	ft_sort_tab(tab, stack.lsta.len);
	ft_sort_stack(&stack, stack.lsta.len, tab);
	 printf("\nfinal stack \n");
	 display_stack(&stack.lsta);
	ft_free_end(tab,&stack.lsta,&stack.lstb);
	}
	return (0);
}

// int	main(int ac, char **av)
// {
// 	int *tab;
// 	t_lst *lst;
// 	t_lst *b;
// 	int i;

// 	lst = NULL;
// 	b = NULL;
// 	tab = ft_valid(ac, av, &lst);
// 	if (!tab)
// 		return (0);
// 	i = 0;
// 	while (i < lst->len)
// 		add_to_queue(lst, tab[i++]);
// 	// ft_supa_algo(................)

// 	free(tab);
// 	display_stack(lst);
// 	ft_free_list(lst);
// 	return (0);
// }