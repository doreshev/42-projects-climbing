/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 21:07:51 by doreshev          #+#    #+#             */
/*   Updated: 2022/04/11 17:47:56 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclength;
	size_t	i;

	i = 0;
	srclength = ft_strlen(src);
	if (!dst)
		return (srclength);
	if (dstsize == 0)
		return (srclength);
	if (srclength >= dstsize)
	{
		ft_memcpy(dst, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	else
		ft_memcpy(dst, src, srclength + 1);
	return (srclength);
}
