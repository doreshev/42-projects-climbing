/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:23:02 by doreshev          #+#    #+#             */
/*   Updated: 2022/04/11 17:25:47 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*n1;
	t_list	*n2;

	if (!lst)
		return ;
	n1 = *lst;
	while (n1)
	{
		n2 = n1->next;
		del(n1->content);
		free(n1);
		n1 = n2;
	}
	*lst = NULL;
}
