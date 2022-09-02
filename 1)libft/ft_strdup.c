/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:22:55 by doreshev          #+#    #+#             */
/*   Updated: 2022/04/11 19:10:40 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	j;
	char	*p;

	i = ft_strlen(s1);
	p = malloc(i + 1);
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
