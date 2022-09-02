/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:28:59 by doreshev          #+#    #+#             */
/*   Updated: 2022/04/10 17:48:18 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_num(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i = 1;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*p;
	int		i;

	if (n == -2147483648)
		return (ft_memcpy(malloc(12), "-2147483648", 12));
	i = ft_num(n);
	p = (char *)malloc(sizeof(char) * (i + 1));
	if (!p)
		return (NULL);
	p[i] = '\0';
	if (n < 0)
	{
		p[0] = '-';
		n = -n;
	}
	if (n == 0)
		p[0] = n + '0';
	while (n > 0)
	{
		p[i - 1] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
	return (p);
}
