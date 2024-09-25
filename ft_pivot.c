/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pivot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 15:25:11 by ayarab            #+#    #+#             */
/*   Updated: 2024/09/25 14:36:56 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_tab(int *tab, int len)
{
	ft_sorting(tab, 0, len - 1);
}

void	ft_sorting(int *tab, int start, int end)
{
	int	pivot_index;

	if (start < end)
	{
		pivot_index = ft_sortintab(tab, start, end);
		ft_sorting(tab, pivot_index + 1, end);
		ft_sorting(tab, start, pivot_index - 1);
	}
}

int	ft_sortintab(int *tab, int start, int end)
{
	int	i;
	int	j;
	int	pivot_value;

	i = start;
	j = start;
	pivot_value = tab[end];
	while (j < end)
	{
		if (tab[j] <= pivot_value)
		{
			ft_swap(&tab[j], &tab[i]);
			i++;
		}
		j++;
	}
	ft_swap(&tab[i], &tab[end]);
	return (i);
}
void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
