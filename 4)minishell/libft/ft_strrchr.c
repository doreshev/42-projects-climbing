/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 12:15:40 by doreshev          #+#    #+#             */
/*   Updated: 2022/04/11 17:48:30 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		length;
	char	i;

	i = c;
	length = ft_strlen(s);
	while (length >= 0)
	{
		if (s[length] == i)
			return ((char *)s + length);
		length--;
	}
	return (NULL);
}
