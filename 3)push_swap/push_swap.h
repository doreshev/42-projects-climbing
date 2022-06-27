/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:28:53 by doreshev          #+#    #+#             */
/*   Updated: 2022/05/23 18:43:44 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_list1
{
	int				content;
	struct s_list1	*next;
}					t_list1;

void	ft_sa(t_list1 **a, int j);
void	ft_pa(t_list1 **a, t_list1 **b, int j);
void	ft_rra(t_list1 **a, int j);
void	ft_ra(t_list1 **a, int j);
void	ft_sb(t_list1 **b, int j);
void	ft_pb(t_list1 **a, t_list1 **b, int j);
void	ft_rrb(t_list1 **b, int j);
void	ft_rb(t_list1 **b, int j);
void	ft_ss(t_list1 **a, t_list1 **b, int j);
void	ft_rr(t_list1 **a, t_list1 **b, int j);
void	ft_rrr(t_list1 **a, t_list1 **b, int j);
void	ft_error(void);
void	ft_sort(t_list1 **a);
void	ft_free(t_list1 **lst);
void	ft_lstadd_back(t_list1 **lst, t_list1 *new);
int		ft_print_rarb(t_list1 **a, t_list1 **b, int c, char s);
int		ft_print_rrarrb(t_list1 **a, t_list1 **b, int c, char s);
int		ft_print_rrarb(t_list1 **a, t_list1 **b, int c, char s);
int		ft_print_rarrb(t_list1 **a, t_list1 **b, int c, char s);
int		ft_checksorted(t_list1 *a);
int		ft_min(t_list1 *a);
int		ft_max(t_list1 *a);
int		ft_lstrchr(t_list1 *a, int i);
int		ft_find_place(t_list1 *b, int c);
int		ft_find_place_a(t_list1 *a, int c);
int		ft_case_rarb_a(t_list1 *a, t_list1 *b, int c);
int		ft_case_rrarrb_a(t_list1 *a, t_list1 *b, int c);
int		ft_case_rrarb_a(t_list1 *a, t_list1 *b, int c);
int		ft_case_rarrb_a(t_list1 *a, t_list1 *b, int c);
int		ft_case_rarb(t_list1 *a, t_list1 *b, int c);
int		ft_case_rrarrb(t_list1 *a, t_list1 *b, int c);
int		ft_case_rrarb(t_list1 *a, t_list1 *b, int c);
int		ft_case_rarrb(t_list1 *a, t_list1 *b, int c);
int		ft_smallest_a(t_list1 *a, t_list1 *b);
int		ft_smallest_b(t_list1 *a, t_list1 *b);
int		ft_lstsize(t_list1 *lst);
int		ft_checkdup(t_list1 *a);
t_list1	*ft_process(int argc, char **argv);
t_list1	*ft_lstlast(t_list1 *lst);
t_list1	*ft_lstnew(int content);

#endif