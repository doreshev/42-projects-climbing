/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:14:22 by doreshev          #+#    #+#             */
/*   Updated: 2022/05/07 16:15:03 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	srclength;
	size_t	dstlength;
	size_t	i;

	i = 0;
	srclength = ft_strlen(src);
	dstlength = ft_strlen(dst);
	if (dstlength >= dstsize)
		return (srclength + dstsize);
	if (dstsize - dstlength <= srclength)
	{
		ft_memcpy(dst + dstlength, src, dstsize - 1);
		dst[dstsize - 1] = '\0';
	}
	else
		ft_memcpy(dst + dstlength, src, srclength + 1);
	return (srclength + dstlength);
}
