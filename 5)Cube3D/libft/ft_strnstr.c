/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:56:52 by doreshev          #+#    #+#             */
/*   Updated: 2022/04/11 20:42:12 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	length;

	if (*needle == '\0')
		return ((char *)haystack);
	length = ft_strlen(needle);
	while (len > 0)
	{
		if (*haystack == '\0' || len < length)
			return (NULL);
		if (ft_strncmp(haystack, needle, length) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
