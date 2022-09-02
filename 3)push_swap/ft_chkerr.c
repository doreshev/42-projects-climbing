/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chkerr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 18:13:28 by doreshev          #+#    #+#             */
/*   Updated: 2022/05/23 18:13:38 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_free(t_list1 **lst)
{
	t_list1	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->content = 0;
		free(*lst);
		*lst = tmp;
	}
}

int	ft_checksorted(t_list1 *a)
{
	int	i;

	i = a->content;
	while (a)
	{
		if (i > a->content)
			return (0);
		i = a->content;
		a = a->next;
	}
	return (1);
}

int	ft_checkdup(t_list1 *a)
{
	t_list1	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->content == tmp->content)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}
