/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d_i_s_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 19:05:53 by doreshev          #+#    #+#             */
/*   Updated: 2022/05/07 22:35:41 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_c(char s)
{
	ft_putchar_fd(s, 1);
	return (1);
}

int	ft_print_s(char *ap)
{
	int	bytes;

	if (!ap)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd(ap, 1);
	bytes = ft_strlen(ap);
	return (bytes);
}

int	ft_print_d_i(int ap)
{
	int		bytes;
	char	*s;

	s = ft_itoa(ap);
	bytes = ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (bytes);
}
