/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:56:19 by doreshev          #+#    #+#             */
/*   Updated: 2022/04/28 15:37:26 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *c)
{
	size_t	i;

	i = 0;
	while (c[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;
	size_t	a;
	size_t	b;

	i = 0;
	j = 0;
	a = ft_strlen(s1);
	b = ft_strlen(s2);
	new = (char *)malloc(sizeof(char) * (a + b + 1));
	if (!new)
		return (NULL);
	while (i < a)
	{
		new[i] = s1[i];
		i++;
	}
	while (j < b)
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}

char	*ft_strdup(char *s1)
{
	size_t	i;
	size_t	j;
	char	*p;

	i = ft_strlen(s1);
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	j = 0;
	while (i > j)
	{
		p[j] = s1[j];
		j++;
	}
	p[j] = '\0';
	return (p);
}

char	*ft_strchr(char *s, int c)
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
