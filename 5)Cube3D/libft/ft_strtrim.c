/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:30:19 by doreshev          #+#    #+#             */
/*   Updated: 2022/04/11 17:49:03 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(char s, char const *p)
{
	while (*p)
	{
		if (*p == s)
			return (1);
		p++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		i;
	int		s1len;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (ft_check(*s1, set))
		s1++;
	s1len = ft_strlen(s1);
	while (s1len > 0 && ft_check(*(s1 + s1len - 1), set))
		s1len--;
	new = malloc(s1len + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s1len > i)
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
