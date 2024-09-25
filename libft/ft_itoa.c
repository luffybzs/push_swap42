/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:21:16 by ayarab            #+#    #+#             */
/*   Updated: 2024/06/05 12:07:13 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(long int n)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long	bjj;
	size_t	len;
	char	*str;

	bjj = n;
	len = ft_len(bjj);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	len = len - 1;
	if (bjj == 0)
		str[0] = 48;
	else if (bjj < 0)
	{
		str[0] = '-';
		bjj = -bjj;
	}
	while (bjj != 0)
	{
		str[len--] = bjj % 10 + '0';
		bjj = bjj / 10;
	}
	return (str);
}
/*
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	int i = -1;
	char *res = ft_itoa(i);
	printf("voici le int transformer en char * %s", res);
	return (0);
}*/