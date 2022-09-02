/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases_a.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 22:10:19 by doreshev          #+#    #+#             */
/*   Updated: 2022/05/22 21:25:56 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_case_rarb_a(t_list1 *a, t_list1 *b, int c)
{
	int	i;

	i = ft_find_place_a(a, c);
	if (i < ft_lstrchr(b, c))
		i = ft_lstrchr(b, c);
	return (i);
}

int	ft_case_rrarrb_a(t_list1 *a, t_list1 *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_a(a, c))
		i = ft_lstsize(a) - ft_find_place_a(a, c);
	if ((i < (ft_lstsize(b) - ft_lstrchr(b, c))) && ft_lstrchr(b, c))
		i = ft_lstsize(b) - ft_lstrchr(b, c);
	return (i);
}

int	ft_case_rarrb_a(t_list1 *a, t_list1 *b, int c)
{
	int	i;

	i = 0;
	if (ft_lstrchr(b, c))
		i = ft_lstsize(b) - ft_lstrchr(b, c);
	i = ft_find_place_a(a, c) + i;
	return (i);
}

int	ft_case_rrarb_a(t_list1 *a, t_list1 *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_a(a, c))
		i = ft_lstsize(a) - ft_find_place_a(a, c);
	i = ft_lstrchr(b, c) + i;
	return (i);
}

int	ft_smallest_a(t_list1 *a, t_list1 *b)
{
	int		i;
	t_list1	*tmp;

	tmp = b;
	i = ft_case_rrarrb_a(a, b, b->content);
	while (tmp)
	{
		if (i > ft_case_rarb_a(a, b, tmp->content))
			i = ft_case_rarb_a(a, b, tmp->content);
		if (i > ft_case_rrarrb_a(a, b, tmp->content))
			i = ft_case_rrarrb_a(a, b, tmp->content);
		if (i > ft_case_rarrb_a(a, b, tmp->content))
			i = ft_case_rarrb_a(a, b, tmp->content);
		if (i > ft_case_rrarb_a(a, b, tmp->content))
			i = ft_case_rrarb_a(a, b, tmp->content);
		tmp = tmp->next;
	}
	return (i);
}
