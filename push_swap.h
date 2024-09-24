/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarab <ayarab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 14:35:59 by ayarab            #+#    #+#             */
/*   Updated: 2024/09/23 18:41:37 by ayarab           ###   ########.fr       */
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
	struct s_node	*target;
}					t_node;

typedef struct s_lst
{
	int				len;
	t_node			*first;
}					t_lst;
typedef struct s_stack
{
	
	struct s_lst lsta;
	struct s_lst lstb;
}			t_stack;		

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
int					*ft_valid(int ac, char **av, t_lst *lst);
void				ft_free_list(t_lst *lst);
void				display_stack(t_lst *lst);
int 				ft_lstlen(t_lst *lst);
int					is_sorted(t_lst *lsta, t_lst *lstb);
int					ft_search_index(t_node *node, t_lst *lst);
void				sort_for_3(t_lst *lsta);
void				sort_for_2(t_lst *lsta, t_lst *lstb);
void				*ft_sort_tab(int *tab, int len);
void				ft_sorting(int *tab, int start, int end);
int					ft_sortintab(int *tab, int start, int end);
void				ft_swap(int *a,int *b);
void				ft_sort_stack(t_stack *both, int len, int *tab);
void				ft_first_half(t_stack *both, int len, int *tab);
void				ft_last_half(t_stack *both, int len, int *tab);
void				ft_sort(t_stack *both);
void				ft_find_target(t_lst *lsta, t_node *node);
int					ft_cost(t_node *lst, t_lst *lsta, t_lst *lstb);
int					ft_cost_top(t_node *lst, t_lst *stack);
void				ft_cost_all(t_lst *lsta, t_lst *lstb);
void				ft_insert(t_lst *stack);
void				ft_rotate_top(t_node *node, t_lst *stack, t_stack *both);
t_node				*ft_lower_price(t_lst *stack);
t_node				*ft_find_lower_price(t_lst *stack);
t_node				*ft_highest(t_node *lst, t_lst *stack);
t_node 				*ft_last(t_node *lst);
t_node				*search_low(t_lst *lst);
t_node				*search_top(t_lst *lst);

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