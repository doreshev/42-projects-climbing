/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:58:21 by doreshev          #+#    #+#             */
/*   Updated: 2022/07/10 20:07:42 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	n = ft_strlen(s1);
	if (n != ft_strlen(s2))
		return (1);
	while (n > i)
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	return (0);
}
