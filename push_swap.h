/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:35:59 by ayarab            #+#    #+#             */
/*   Updated: 2024/09/11 19:55:40 by ayarab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_node
{
	int				index;
	int				cost;
	int				content;
	struct s_node	*next;
}					t_node;

typedef struct s_lst
{
	int				len;
	t_node			*first;
}					t_lst;
//
t_lst				*ft_init_stack(void);
t_lst				*ft_lstnew(int content);
long				ft_atoi_int(char *str);
char				*ft_input(char **av);
void				add_to_queue(t_lst *lst, int nbr);
int					ft_isdigit_push_swap(char **str);
int					ft_check_str(char **res);
char				*ft_strjoin_free(char *s1, char *s2);
void				ft_free_tab(char **res);
char				**ft_parsing(int ac, char **av);
int					ft_isdigit_string(char *str);
int					*ft_init_tab(char **res, t_lst *lst);
int					ft_strlen_tab(char **res);
int					*ft_valid(int ac, char **av, t_lst **lst);
void				ft_free_list(t_lst *lst);
void				display_stack(t_lst *lst);
int 				ft_lstlen(t_lst *lst);
t_node 	*ft_last(t_node *lst);

// push
void				ft_push(t_lst *lsta, t_lst *lstb);

// swap
void				swap(t_lst *lst);
void				ft_sa(t_lst *lsta);
void				ft_sb(t_lst *lstb);
void				ft_ss(t_lst *lsta, t_lst *lstb);
// rotate
t_node				*ft_last(t_node *lst);
void				rotate(t_lst *lst);
void				ft_ra(t_lst *lst);
void				ft_rb(t_lst *lst);
void				ft_rr(t_lst *lsta, t_lst *lstb);
// reverse rotate
t_node				ft_second_last(t_node *lst);
void				reverse_rotate(t_lst *lst);
void				ft_rra(t_lst *lst);
void				ft_rrb(t_lst *lst);
void				ft_rrr(t_lst *lsta, t_lst *lstb);
#endif