/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:07:06 by doreshev          #+#    #+#             */
/*   Updated: 2022/05/03 19:46:16 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sub1(unsigned long int ap, char *s, int bytes)
{
	if (s)
	{
		bytes = bytes - 1;
		while (ap != 0)
		{
			s[bytes] = (ap % 10) + 48;
			ap = ap / 10;
			bytes--;
		}
		bytes = ft_strlen(s);
		ft_putstr_fd(s, 1);
	}
	return (bytes);
}

int	ft_print_u(unsigned int ap)
{
	unsigned int	i;
	int				bytes;
	char			*s;

	if (ap == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	i = ap;
	bytes = 0;
	while (i != 0)
	{
		i = i / 10;
		bytes++;
	}
	s = ft_calloc(1, sizeof(char) * (bytes + 1));
	if (s)
		bytes = ft_sub1(ap, s, bytes);
	free(s);
	return (bytes);
}
