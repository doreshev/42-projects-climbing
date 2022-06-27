/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_commands.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 17:58:13 by doreshev          #+#    #+#             */
/*   Updated: 2022/05/23 18:38:51 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_print_rarb(t_list1 **a, t_list1 **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->content != c && ft_find_place(*b, c) > 0)
			ft_rr(a, b, 0);
		while ((*a)->content != c)
			ft_ra(a, 0);
		while (ft_find_place(*b, c) > 0)
			ft_rb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while ((*b)->content != c && ft_find_place_a(*a, c) > 0)
			ft_rr(a, b, 0);
		while ((*b)->content != c)
			ft_rb(b, 0);
		while (ft_find_place_a(*a, c) > 0)
			ft_ra(a, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

int	ft_print_rrarrb(t_list1 **a, t_list1 **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->content != c && ft_find_place(*b, c) > 0)
			ft_rrr(a, b, 0);
		while ((*a)->content != c)
			ft_rra(a, 0);
		while (ft_find_place(*b, c) > 0)
			ft_rrb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while ((*b)->content != c && ft_find_place_a(*a, c) > 0)
			ft_rrr(a, b, 0);
		while ((*b)->content != c)
			ft_rrb(b, 0);
		while (ft_find_place_a(*a, c) > 0)
			ft_rra(a, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

int	ft_print_rrarb(t_list1 **a, t_list1 **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->content != c)
			ft_rra(a, 0);
		while (ft_find_place(*b, c) > 0)
			ft_rb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while (ft_find_place_a(*a, c) > 0)
			ft_rra(a, 0);
		while ((*b)->content != c)
			ft_rb(b, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}

int	ft_print_rarrb(t_list1 **a, t_list1 **b, int c, char s)
{
	if (s == 'a')
	{
		while ((*a)->content != c)
			ft_ra(a, 0);
		while (ft_find_place(*b, c) > 0)
			ft_rrb(b, 0);
		ft_pb(a, b, 0);
	}
	else
	{
		while (ft_find_place_a(*a, c) > 0)
			ft_ra(a, 0);
		while ((*b)->content != c)
			ft_rrb(b, 0);
		ft_pa(a, b, 0);
	}
	return (-1);
}
