/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 13:55:53 by doreshev          #+#    #+#             */
/*   Updated: 2022/06/16 12:39:37 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_sub2(int bytes, char *s, unsigned long int ap, int dif)
{
	while (ap != 0)
	{
		if (ap % 16 < 10)
			s[bytes] = (ap % 16) + 48;
		else
			s[bytes] = (ap % 16) + dif;
		ap = ap / 16;
		bytes--;
	}
	bytes = ft_strlen(s);
	ft_putstr_fd(s, 1);
	return (bytes);
}

int	ft_print_p(unsigned long int ap)
{
	unsigned long int		i;
	int						bytes;
	char					*s;

	if (ap == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	i = ap;
	bytes = 0;
	while (i != 0)
	{
		i = i / 16;
		bytes++;
	}
	s = ft_calloc(1, sizeof(char) * (bytes + 1));
	if (s)
	{
		ft_putstr_fd("0x", 1);
		bytes = ft_sub2(bytes - 1, s, ap, 87) + 2;
	}
	free(s);
	return (bytes);
}

int	ft_print_x(unsigned int ap, int dif)
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
		i = i / 16;
		bytes++;
	}
	s = ft_calloc(1, sizeof(char) * (bytes + 1));
	if (s)
		bytes = ft_sub2(bytes - 1, s, ap, dif);
	free(s);
	return (bytes);
}
