/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:35:59 by ayarab            #+#    #+#             */
/*   Updated: 2024/09/07 18:22:54 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	int				index;
	int				cost;
	int				content;
	struct s_list	*next;
	struct s_list	*prev;
	struct s_list 	*target;
}					t_list;

typedef struct s_stack
{
	struct s_list	*first;
}					t_stack;

long				ft_atoi_int(char *str);
char				*ft_input(char **av);
int					ft_isdigit_push_swap(char **str);
int					ft_check_str(char **res);
char				*ft_strjoin_free(char *s1, char *s2);
void				ft_free_tab(char **res);
char 				**ft_parsing(int ac, char **av);
int 				ft_isdigit_string(char *str);
int 				*ft_init_tab(char **res);
int					ft_strlen_tab(char **res);


#endif