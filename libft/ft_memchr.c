/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:32:44 by ayarab            #+#    #+#             */
/*   Updated: 2024/06/03 13:07:26 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int chr, size_t len)
{
	const unsigned char	*src;
	unsigned char		search;
	size_t				i;

	i = 0;
	src = (unsigned char *)str;
	search = (unsigned char)chr;
	while (i < len)
	{
		if (src[i] == search)
		{
			return ((void *)src + i);
		}
		i++;
	}
	return (NULL);
}
