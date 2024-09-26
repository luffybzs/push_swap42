/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:21:01 by ayarab            #+#    #+#             */
/*   Updated: 2024/09/26 18:41:57 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_free(char **res)
{
	size_t	i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
	return ;
}

static size_t	ft_countlen(char const *str, char c)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] != c)
			len++;
		while (str[i] != c && str[i])
			i++;
		if (str[i])
			i++;
	}
	return (len);
}

static size_t	ft_lenword(const char *str, char c, int pos)
{
	size_t	i;
	size_t	len;

	i = pos;
	len = 0;
	while (str[i] != c && str[i])
	{
		len++;
		i++;
	}
	return (len);
}

char	*ft_split2(char *str, char c, char **res, int i)
{
	size_t	k;
	size_t	j;

	k = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c)
		{
			res[j] = malloc(sizeof(char) * (ft_lenword(str, c, i) + 1));
			if (!res)
				return (ft_free(res), NULL);
			while (str[i] != c && str[i])
				res[j][k++] = str[i++];
			res[j][k] = 0;
			k = 0;
			j++;
		}
		else
			i++;
	}
	res[j] = NULL;
	return (str);
}

char	**ft_split(char const *str, char c)
{
	size_t	i;
	char	**res;

	i = 0;
	if (!str)
		return (NULL);
	if (!*str)
	{
		res = malloc(sizeof(char *) * 1);
		if (!res)
			return (NULL);
		res[0] = NULL;
		return (res);
	}
	res = malloc(sizeof(char *) * (ft_countlen(str, c) + 1));
	if (!res)
		return (NULL);
	while (str[i] == c)
		i++;
	if (!ft_split2((char *)str, c, res, i))
		return (ft_free(res), NULL);
	return (res);
}
/*
 int	main(void)
 {
	char **tab;
	char *str = "hello!";
	char  l = ' ';
		int i;
	tab = ft_split(str,l);
	i = 0;
		while (i < 2)
			printf("%s\n", tab[i++]);
		ft_free(tab);
	return (0);
}
*/