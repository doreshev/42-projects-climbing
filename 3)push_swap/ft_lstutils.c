/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:54:56 by doreshev          #+#    #+#             */
/*   Updated: 2022/05/22 20:10:49 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list1 *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

t_list1	*ft_lstlast(t_list1 *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list1	*ft_lstnew(int content)
{
	t_list1	*new;

	new = malloc(sizeof (t_list1));
	if (!new)
		ft_error();
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_list1 **lst, t_list1 *new)
{
	if (!lst)
		return ;
	if (!*lst)
		*lst = new;
	else
		(ft_lstlast(*lst))->next = new;
}
