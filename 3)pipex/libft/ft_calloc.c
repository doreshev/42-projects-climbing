/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:22:35 by doreshev          #+#    #+#             */
/*   Updated: 2022/04/29 16:25:14 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	i;

	i = size * count;
	if (i == 0)
		i = 1;
	if (size > 0 && (18446744073709551615UL / size) < count)
		return (NULL);
	p = malloc(i);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, i);
	return (p);
}
