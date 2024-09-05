/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:20:52 by ayarab            #+#    #+#             */
/*   Updated: 2024/06/13 14:30:29 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_ptr(unsigned long a, char *base)
{
	if (a == 0)
	{
		return (ft_putstr("(nil)"));
	}
	return (ft_putstr("0x") + ft_putnbr_base(a, base));
}
