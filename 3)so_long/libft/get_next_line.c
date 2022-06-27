/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 21:56:01 by doreshev          #+#    #+#             */
/*   Updated: 2022/05/11 18:40:56 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_sub(char **ost, char **line)
{
	char	*s;

	s = NULL;
	if (*ost)
	{
		*line = *ost;
		s = ft_strchr(*ost, '\n');
		if (s)
		{
			s++;
			if (*s != '\0')
				*ost = ft_strdup(s);
			else
				*ost = NULL;
			*s = '\0';
		}
		else
			*ost = NULL;
	}
	else
	{
		*line = (char *)malloc(sizeof(char) * 1);
		*line[0] = '\0';
	}
	return (s);
}

char	*ft_sub1(char **ost, char **line, char **buf)
{
	char	*s;
	char	*tmp;

	s = ft_strchr(*buf, '\n');
	if (s)
	{
		s++;
		if (*s != '\0')
			*ost = ft_strdup(s);
		*s = '\0';
	}
	tmp = *line;
	*line = ft_strjoin(*line, *buf);
	free(tmp);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*buf;
	int			i;
	char		*s;
	static char	*ost[OPEN_MAX];
	char		*line;

	if (BUFFER_SIZE < 1 || read(fd, 0, 0) == -1 || fd < 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	s = ft_sub(&ost[fd], &line);
	i = 1;
	while (!s && i)
	{
		i = read(fd, buf, BUFFER_SIZE);
		buf[i] = '\0';
		s = ft_sub1(&ost[fd], &line, &buf);
	}
	free(buf);
	if (ft_strlen(line) > 0)
		return (line);
	free (line);
	return (NULL);
}
