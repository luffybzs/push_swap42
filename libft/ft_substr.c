/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 10:01:23 by ayarab            #+#    #+#             */
/*   Updated: 2024/05/30 18:04:47 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_error(void)
{
	char	*error;

	error = malloc(1);
	if (!error)
		return (NULL);
	error[0] = 0;
	return (error);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	strlen;

	i = 0;
	if (!str)
		return (NULL);
	strlen = ft_strlen(str);
	if (start >= strlen)
		return (ft_error());
	if (len > strlen - start)
		len = strlen - start;
	substr = (char *)malloc((len + 1) * sizeof(*str));
	if (!substr)
		return (NULL);
	while (i < len && str[start + i])
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
