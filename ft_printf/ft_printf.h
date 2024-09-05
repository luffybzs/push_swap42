/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:53:27 by ayarab            #+#    #+#             */
/*   Updated: 2024/06/13 14:30:47 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putstr(const char *str);
int		ft_putchar(const char c);
int		ft_strlen(const char *str);
int		print_ptr(unsigned long a, char *base);
long	ft_putnbr_base(unsigned long n, char *base);
int		sign_check(long n, char *base);

#endif