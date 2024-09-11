/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 12:08:30 by ayarab            #+#    #+#             */
/*   Updated: 2024/09/11 19:20:38 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_lst *lsta, t_lst *lstb)
{
	t_node	*current;

	if (lsta->first == NULL)
		return;
	current = lsta->first;
	lsta->first = current->next;
	
	current->next = lstb->first;
	lstb->first = current;
	// if (lstb->first == NULL)
	// {
	// 	lstb->first = current;
	// 	current->next = NULL;
	// 	lsta->first = new_top;
	// }
	// else
	// {
	// 	lstb->first->next = current;
	// 	lsta->first = new_top;
	// }
}

int	main(void)
{
	int tab[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	t_lst *lsta;
	t_lst *lstb;
	int i = 0;

	lsta = ft_init_stack();
	lstb = ft_init_stack();

	while (i < 8)
	{
		add_to_queue(lsta, tab[i++]);
	}
	printf("stack a avant = \n");
	display_stack(lsta);
	ft_push(lsta,lstb);
	ft_push(lsta,lstb);
	ft_push(lsta,lstb);
	ft_push(lsta,lstb);
	printf("----------------------------\n");
	display_stack(lstb);
	printf("----------------------------\n");
	printf("rotate = \n");
	printf("----------------------------\n");
	ft_rr(lsta,lstb);
	printf("----------------------------\n");
	display_stack(lstb);
	printf("----------------------------\n");
	display_stack(lsta);
	//printf("swap b = \n");
	//display_stack(lstb);
	// printf("stack b avant = \n");
	// display_stack(lstb);
	// ft_push(lsta, lstb);
	// ft_push(lsta,lstb);
	// printf("stack a apres = \n");
	// display_stack(lsta);
	// printf("stack b apres = \n");
	// display_stack(lstb);
	// printf("stack apres un push = \n");
	// ft_push(lstb, lsta);
	// display_stack(lsta);
	return (0);
}