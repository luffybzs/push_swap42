/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:34:07 by ayarab            #+#    #+#             */
/*   Updated: 2024/05/30 18:05:21 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *str, char (*f)(unsigned int, char))
{
	char	*reslut;
	size_t	i;

	if (!str || !f)
	{
		return (NULL);
	}
	reslut = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	if (!reslut)
	{
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		reslut[i] = f(i, str[i]);
		i++;
	}
	reslut[i] = '\0';
	return (reslut);
}
