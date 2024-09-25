/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 13:14:53 by ayarab            #+#    #+#             */
/*   Updated: 2024/06/05 13:43:19 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charset(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	start;
	size_t	end;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_charset(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_charset(s1[end - 1], set))
		end--;
	res = malloc(sizeof(*s1) * (end - start) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (start < end)
	{
		res[i++] = s1[start++];
	}
	res[i] = '\0';
	return (res);
}
