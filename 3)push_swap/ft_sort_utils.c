/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 17:17:34 by doreshev          #+#    #+#             */
/*   Updated: 2022/05/22 20:15:36 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min(t_list1 *a)
{
	int		i;

	i = a->content;
	while (a)
	{
		if (a->content < i)
			i = a->content;
		a = a->next;
	}
	return (i);
}

int	ft_max(t_list1 *a)
{
	int		i;

	i = a->content;
	while (a)
	{
		if (a->content > i)
			i = a->content;
		a = a->next;
	}
	return (i);
}

int	ft_lstrchr(t_list1 *a, int c)
{
	int		i;

	i = 0;
	while (a->content != c)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	ft_find_place(t_list1 *b, int c)
{
	int		i;
	t_list1	*tmp;

	i = 1;
	if (c > b->content && c < ft_lstlast(b)->content)
		i = 0;
	else if (c > ft_max(b) || c < ft_min(b))
		i = ft_lstrchr(b, ft_max(b));
	else
	{
		tmp = b->next;
		while (b->content < c || tmp->content > c)
		{
			b = b->next;
			tmp = b->next;
			i++;
		}
	}
	return (i);
}

int	ft_find_place_a(t_list1 *a, int c)
{
	int		i;
	t_list1	*tmp;

	i = 1;
	if (c < a->content && c > ft_lstlast(a)->content)
		i = 0;
	else if (c > ft_max(a) || c < ft_min(a))
		i = ft_lstrchr(a, ft_min(a));
	else
	{
		tmp = a->next;
		while (a->content > c || tmp->content < c)
		{
			a = a->next;
			tmp = a->next;
			i++;
		}
	}
	return (i);
}
