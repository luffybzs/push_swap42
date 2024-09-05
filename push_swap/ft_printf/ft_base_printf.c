/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 15:37:38 by ayarab            #+#    #+#             */
/*   Updated: 2024/06/13 14:28:31 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long	ft_putnbr_base(unsigned long n, char *base)
{
	unsigned long	baselen;
	unsigned long	i;

	baselen = ft_strlen(base);
	i = 0;
	if (n >= baselen)
	{
		i += ft_putnbr_base(n / baselen, base);
		i += ft_putnbr_base(n % baselen, base);
	}
	else
	{
		ft_putchar(base[n]);
		i++;
	}
	return (i);
}

int	sign_check(long n, char *base)
{
	if (n < 0)
		return (ft_putchar('-') + ft_putnbr_base(-n, base));
	return (ft_putnbr_base(n, base));
}
