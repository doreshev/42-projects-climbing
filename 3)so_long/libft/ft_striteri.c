/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:33:38 by doreshev          #+#    #+#             */
/*   Updated: 2022/04/10 14:46:51 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int		i;
	int		length;

	if (!s || !f)
		return ;
	length = ft_strlen(s);
	i = 0;
	while (i < length)
	{
		(*f)(i, &s[i]);
		i++;
	}
}
