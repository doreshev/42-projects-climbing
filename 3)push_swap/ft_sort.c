/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:25:53 by doreshev          #+#    #+#             */
/*   Updated: 2022/05/23 18:40:16 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_list1 **a)
{
	if (ft_min(*a) == (*a)->content)
	{
		ft_rra(a, 0);
		ft_sa(a, 0);
	}
	else if (ft_max(*a) == (*a)->content)
	{
		ft_ra(a, 0);
		if (!ft_checksorted(*a))
			ft_sa(a, 0);
	}
	else
	{
		if (ft_lstrchr(*a, ft_max(*a)) == 1)
			ft_rra(a, 0);
		else
			ft_sa(a, 0);
	}
}

void	ft_sort_b2(t_list1 **a, t_list1 **b)
{
	int		i;
	t_list1	*tmp;

	while (ft_lstsize(*a) > 3 && !ft_checksorted(*a))
	{
		tmp = *a;
		i = ft_smallest_b(*a, *b);
		while (i >= 0)
		{
			if (i == ft_case_rarb(*a, *b, tmp->content))
				i = ft_print_rarb(a, b, tmp->content, 'a');
			else if (i == ft_case_rrarrb(*a, *b, tmp->content))
				i = ft_print_rrarrb(a, b, tmp->content, 'a');
			else if (i == ft_case_rarrb(*a, *b, tmp->content))
				i = ft_print_rarrb(a, b, tmp->content, 'a');
			else if (i == ft_case_rrarb(*a, *b, tmp->content))
				i = ft_print_rrarb(a, b, tmp->content, 'a');
			else
				tmp = tmp->next;
		}
	}
}

t_list1	*ft_sort_b(t_list1 **a)
{
	t_list1	*b;

	b = NULL;
	if (ft_lstsize(*a) > 3 && !ft_checksorted(*a))
		ft_pb(a, &b, 0);
	if (ft_lstsize(*a) > 3 && !ft_checksorted(*a))
		ft_pb(a, &b, 0);
	if (!ft_checksorted(*a) && ft_lstsize(*a) > 3)
		ft_sort_b2(a, &b);
	if (!ft_checksorted(*a))
		ft_sort_3(a);
	return (b);
}

t_list1	**ft_sort_a(t_list1 **a, t_list1 **b)
{
	int		i;
	t_list1	*tmp;

	while (*b)
	{
		tmp = *b;
		i = ft_smallest_a(*a, *b);
		while (i >= 0)
		{
			if (i == ft_case_rarb_a(*a, *b, tmp->content))
				i = ft_print_rarb(a, b, tmp->content, 'b');
			else if (i == ft_case_rarrb_a(*a, *b, tmp->content))
				i = ft_print_rarrb(a, b, tmp->content, 'b');
			else if (i == ft_case_rrarrb_a(*a, *b, tmp->content))
				i = ft_print_rrarrb(a, b, tmp->content, 'b');
			else if (i == ft_case_rrarb_a(*a, *b, tmp->content))
				i = ft_print_rrarb(a, b, tmp->content, 'b');
			else
				tmp = tmp->next;
		}
	}
	return (a);
}

void	ft_sort(t_list1 **a)
{
	t_list1	*b;
	int		i;

	b = NULL;
	if (ft_lstsize(*a) == 2)
		ft_sa(a, 0);
	else
	{
		b = ft_sort_b(a);
		a = ft_sort_a(a, &b);
		i = ft_lstrchr(*a, ft_min(*a));
		if (i < ft_lstsize(*a) - i)
		{
			while ((*a)->content != ft_min(*a))
				ft_ra(a, 0);
		}
		else
		{
			while ((*a)->content != ft_min(*a))
				ft_rra(a, 0);
		}
	}
}
