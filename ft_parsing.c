/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 15:06:25 by ayarab            #+#    #+#             */
/*   Updated: 2024/09/12 15:07:08 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_init_tab(char **res, t_lst *lst)
{
	int	i;
	int	*tab;

	i = 0;
	lst->len = ft_strlen_tab(res);
	tab = malloc(sizeof(int) * (lst->len));
	if (!tab)
		return (NULL);
	while (i < lst->len)
	{
		tab[i] = ft_atoi_int(res[i]);
		i++;
	}
	return (tab);
}
int	*ft_valid(int ac, char **av, t_lst **lst)
{
	char	**res;
	int		*tab;

	res = ft_parsing(ac, av);
	if (!res)
		return (NULL);
	*lst = ft_init_stack();
	if (!*lst)
		return (ft_free_tab(res), NULL);
	tab = ft_init_tab(res, *lst);
	if (!tab)
		return (ft_free_tab(res), ft_free_list(*lst), NULL);
	return (ft_free_tab(res), tab);
}