/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:36:07 by ayarab            #+#    #+#             */
/*   Updated: 2024/09/26 17:07:17 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ft(int *tab, t_lst *lsta, t_lst *lstb)
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
int	ft_check_empty(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac > 1)
	{
		if (av[1][0] == '\0')
			return (0);
		else if (av[1][0] == ' ')
		{
			while (av[1][i] == 32 && av[1][i])
				i++;
			if (av[1][i] == '\0')
				return (0);
		}
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		*tab;
	int		i;
	t_stack	stack;

	i = 0;
	stack.lsta.first = NULL;
	stack.lstb.first = NULL;
	if (ft_check_empty(ac, av) == 0)
		return (0);
	tab = ft_valid(ac, av, &stack.lsta);
	if (!tab)
		return (0);
	while (i < stack.lsta.len)
		add_to_queue(&stack.lsta, tab[i++]);
	if (is_sorted(&stack.lsta, &stack.lstb) == 1)
		return (ft_ft(tab, &stack.lsta, &stack.lstb), 0);
	if (stack.lsta.len == 2)
		return (ft_sort_2(&stack.lsta, &stack.lstb), ft_ft(tab, &stack.lsta,
				&stack.lstb), 0);
	else if (stack.lsta.len == 3)
		return (ft_3(&stack.lsta), ft_ft(tab, &stack.lsta, &stack.lstb), 0);
	ft_sort_tab(tab, stack.lsta.len);
	ft_sort_stack(&stack, stack.lsta.len, tab);
	ft_ft(tab, &stack.lsta, &stack.lstb);
	return (0);
}
