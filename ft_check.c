/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:34:45 by ayarab            #+#    #+#             */
/*   Updated: 2024/09/25 15:34:11 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

long	ft_atoi_int(char *str)
{
	size_t		i;
	long int	res;
	int			sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res += str[i] - 48;
		i++;
		if (res * sign > 2147483647 || res * sign < -2147483648)
			return (2147483648);
	}
	return (res * sign);
}
char	*ft_input(char **av)
{
	int		i;
	char	*str;
	char	*space;

	space = ft_strdup(" ");
	if (space == NULL)
		return (NULL);
	i = 1;
	str = ft_strdup(av[i]);
	if (!str)
		return (free(space), NULL);
	while (av[i + 1])
	{
		str = ft_strjoin_free(str, space);
		if (!str)
			return (free(space), NULL);
		str = ft_strjoin_free(str, av[i + 1]);
		if (!str)
			return (free(space), NULL);
		i++;
	}
	free(space);
	return (str);
}
int	ft_isdigit_push_swap(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[j][0] == '\0')
		return (0);
	while (str[j])
	{
		if (str[j][0] == '-' || str[j][0] == '+')
			i++;
		while (str[j][i] && str[j][i] >= '0' && str[j][i] <= '9')
			i++;
		if (str[j][i] != '\0')
			return (ft_putendl_fd("error", 2), 0);
		j++;
		i = 0;
	}
	return (1);
}
int	ft_check_str(char **res)
{
	int			i;
	int			j;
	long int	nb1;
	long int	nb2;

	j = -1;
	nb1 = 0;
	nb2 = 0;
	if (ft_isdigit_push_swap(res) == 0)
		return (0);
	while (res[++j])
	{
		i = j + 1;
		nb1 = ft_atoi_int(res[j]);
		if (nb1 == 2147483648)
			return (ft_putendl_fd("error", 2), 0);
		while (res[i])
		{
			nb2 = ft_atoi_int(res[i]);
			if (nb1 == nb2 || nb1 >= 2147483648 || nb2 >= 2147483648)
				return (ft_putendl_fd("error", 2), 0);
			i++;
		}
	}
	return (1);
}

char	**ft_parsing(int ac, char **av)
{
	char	*str;
	char	**res;
	int		i;

	i = 0;
	if (ac > 1)
	{
		str = ft_input(av);
		if (!str)
			return (free(str), NULL);
		res = ft_split(str, ' ');
		if (!res)
			return (free(str), NULL);
		if (ft_check_str(res) == 0)
			return (free(str), ft_free_tab(res), NULL);
		else
			return (free(str), res);
	}
	return (NULL);
}
// int main(int ac, char **av)
// {
// 	char **res;
// 	int *tab;
// 	int i = 0;
// 	res = ft_parsing(ac,av);
// 	if (!res)
// 		return (0);
// 	tab = ft_init_tab(res);
// 	while (res[i])
// 	{
// 		printf("%d\n", tab[i]);
// 		i++;
// 	}
// 	ft_free_tab(res);
// 	free (tab);
// 	return (0);
// }
