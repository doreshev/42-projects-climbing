/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cases_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 20:13:47 by doreshev          #+#    #+#             */
/*   Updated: 2022/05/22 21:26:19 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_case_rarb(t_list1 *a, t_list1 *b, int c)
{
	int	i;

	i = ft_find_place(b, c);
	if (i < ft_lstrchr(a, c))
		i = ft_lstrchr(a, c);
	return (i);
}

int	ft_case_rrarrb(t_list1 *a, t_list1 *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place(b, c))
		i = ft_lstsize(b) - ft_find_place(b, c);
	if ((i < (ft_lstsize(a) - ft_lstrchr(a, c))) && ft_lstrchr(a, c))
		i = ft_lstsize(a) - ft_lstrchr(a, c);
	return (i);
}

int	ft_case_rrarb(t_list1 *a, t_list1 *b, int c)
{
	int	i;

	i = 0;
	if (ft_lstrchr(a, c))
		i = ft_lstsize(a) - ft_lstrchr(a, c);
	i = ft_find_place(b, c) + i;
	return (i);
}

int	ft_case_rarrb(t_list1 *a, t_list1 *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place(b, c))
		i = ft_lstsize(b) - ft_find_place(b, c);
	i = ft_lstrchr(a, c) + i;
	return (i);
}

int	ft_smallest_b(t_list1 *a, t_list1 *b)
{
	int		i;
	t_list1	*tmp;

	tmp = a;
	i = ft_case_rrarrb(a, b, a->content);
	while (tmp)
	{
		if (i > ft_case_rarb(a, b, tmp->content))
			i = ft_case_rarb(a, b, tmp->content);
		if (i > ft_case_rrarrb(a, b, tmp->content))
			i = ft_case_rrarrb(a, b, tmp->content);
		if (i > ft_case_rarrb(a, b, tmp->content))
			i = ft_case_rarrb(a, b, tmp->content);
		if (i > ft_case_rrarb(a, b, tmp->content))
			i = ft_case_rrarb(a, b, tmp->content);
		tmp = tmp->next;
	}
	return (i);
}
