/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:35:59 by ayarab            #+#    #+#             */
/*   Updated: 2024/09/04 19:48:30 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H


# include <stdlib.h>
# include <string.h>
# include <unistd.h>
#include "./libft/libft.h"

long ft_atoi_int(char *str);
char *ft_input(char **av);
int ft_isdigit_push_swap(char **str);
int ft_check_str(char **res);
char	*ft_strjoin_free(char *s1, char *s2);
void ft_free_tab(char **res);
#endif