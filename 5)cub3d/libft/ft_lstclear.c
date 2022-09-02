/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:23:02 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/05 18:04:43 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*n1;
	t_list	*n2;

	if (!lst)
		return ;
	n1 = *lst;
	while (n1)
	{
		n2 = n1->next;
		free(n1);
		n1 = n2;
	}
	*lst = NULL;
}
