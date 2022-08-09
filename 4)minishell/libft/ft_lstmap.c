/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:40:14 by doreshev          #+#    #+#             */
/*   Updated: 2022/04/11 17:45:25 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nodes;
	t_list	*new;

	new = NULL;
	while (lst)
	{
		nodes = ft_lstnew(f(lst->content));
		if (!nodes)
			ft_lstclear(&new, del);
		else
			ft_lstadd_back(&new, nodes);
		lst = lst->next;
	}
	return (new);
}
