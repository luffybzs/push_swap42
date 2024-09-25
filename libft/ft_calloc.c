/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:50:59 by ayarab            #+#    #+#             */
/*   Updated: 2024/06/05 13:49:42 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t len)
{
	char	*total;
	size_t	i;

	i = 0;
	if (len != 0)
	{
		if (len > __SIZE_MAX__ / count)
			return (0);
	}
	total = (char *)malloc(count * len);
	if (total == 0)
		return (0);
	while (i < count * len)
	{
		total[i] = 0;
		i++;
	}
	return ((void *)total);
}
