/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 16:38:39 by doreshev          #+#    #+#             */
/*   Updated: 2022/05/07 22:35:56 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_parameter(va_list ap, char fmt)
{
	int	bytes;

	bytes = 0;
	if (fmt == 'c')
		bytes = ft_print_c(va_arg(ap, int));
	else if (fmt == '%')
		bytes = ft_print_c('%');
	else if (fmt == 's')
		bytes = ft_print_s(va_arg(ap, char *));
	else if (fmt == 'p')
		bytes = ft_print_p(va_arg(ap, unsigned long int));
	else if ((fmt == 'd') || (fmt == 'i'))
		bytes = ft_print_d_i(va_arg(ap, int));
	else if (fmt == 'u')
		bytes = ft_print_u(va_arg(ap, unsigned int));
	else if (fmt == 'x')
		bytes = ft_print_x(va_arg(ap, unsigned int), 87);
	else if (fmt == 'X')
		bytes = ft_print_x(va_arg(ap, unsigned int), 55);
	return (bytes);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		bytes;
	int		i;

	if (!fmt)
		return (-1);
	va_start(ap, fmt);
	i = 0;
	bytes = 0;
	while (fmt[i])
	{
		if (fmt[i] != '%')
			bytes = ft_print_c(fmt[i]) + bytes;
		else
		{
			i++;
			bytes = bytes + ft_check_parameter(ap, fmt[i]);
		}
		i++;
	}
	va_end(ap);
	return (bytes);
}
