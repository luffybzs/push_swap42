/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 12:00:39 by ayarab            #+#    #+#             */
/*   Updated: 2024/06/26 14:23:25 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_character(va_list *av, char c)
{
	int	n;

	n = 0;
	if (c == 'c')
		n += ft_putchar(va_arg(*av, int));
	else if (c == 's')
		n += ft_putstr(va_arg(*av, char *));
	else if (c == 'd' || c == 'i')
		n += sign_check((long)va_arg(*av, int), "0123456789");
	else if (c == 'x')
		n += sign_check((long)va_arg(*av, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		n += sign_check((long)va_arg(*av, unsigned int), "0123456789ABCDEF");
	else if (c == 'u')
		n += sign_check((long)va_arg(*av, unsigned int), "0123456789");
	else if (c == '%')
		n += ft_putchar('%');
	else if (c == 'p')
		n += print_ptr((unsigned long)va_arg(*av, void *), "0123456789abcdef");
	else
		n += ft_putchar('%') + ft_putchar(c);
	return (n);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		i;
	int		res;

	va_start(list, str);
	i = 0;
	res = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '%')
		{
			res += ft_check_character(&list, str[i + 1]);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			res++;
		}
		i++;
	}
	va_end(list);
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	int i;
	unsigned int hexa;
	char *str;

	str[] = "ayoub test12"; 
	hexa = 42;
	i = __INT_MAX__;
	
	ft_printf("test 1 %c\n", 'c');
	ft_printf("test 2 %s\n", str);
	ft_printf("test 3 %i\n", i);
	ft_printf("test 4 %d\n", i);
	ft_printf("test 5 %x\n", hexa);
	ft_printf("test 6 %X\n", hexa);
	ft_printf("test 7 %p", str);
	ft_printf("test 8 %%");
	ft_printf("test 9 %!");
	ft_printf("");

	printf("test 1 %c\n", 'c');
	printf("test 2 %s\n", str);
	printf("test 3 %i\n", i);
	printf("test 4 %d\n", i);
	printf("test 5 %x\n", hexa);
	printf("test 6 %X\n", hexa);
	printf("test 7 %p", str);
	printf("test 8 %%");
	printf("test 9 %!");
	printf("");
}
*/