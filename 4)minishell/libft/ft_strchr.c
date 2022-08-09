/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:15:40 by doreshev          #+#    #+#             */
/*   Updated: 2022/04/08 22:04:40 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	i;

	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	while (*s != '\0')
	{
		i = c;
		if (*s == i)
			return ((char *)s);
		s++;
	}
	return (NULL);
}
