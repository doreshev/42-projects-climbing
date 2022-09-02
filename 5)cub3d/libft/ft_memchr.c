/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:56:00 by doreshev          #+#    #+#             */
/*   Updated: 2022/04/08 21:56:06 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ch;
	size_t			i;

	ch = (unsigned char *)s;
	i = 0;
	while (n > i)
	{
		if (*ch == (unsigned char)c)
			return (ch);
		ch++;
		i++;
	}
	return (NULL);
}
