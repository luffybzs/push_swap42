/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:33:48 by ayarab            #+#    #+#             */
/*   Updated: 2024/05/30 18:07:08 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *d, const void *s, size_t len)
{
	size_t	i;
	char	*des;
	char	*src;

	if (!d && !s)
	{
		return (NULL);
	}
	des = (char *)d;
	src = (char *)s;
	i = 0;
	while (i < len)
	{
		des[i] = src[i];
		i++;
	}
	return (d);
}
