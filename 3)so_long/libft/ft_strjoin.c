/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:12:42 by doreshev          #+#    #+#             */
/*   Updated: 2022/06/01 11:53:10 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	size_t	i;
	size_t	length;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(length + 1);
	if (!new)
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	length = i;
	while (s2[i - length])
	{
		new[i] = s2[i - length];
		i++;
	}
	new[i] = '\0';
	return (new);
}
