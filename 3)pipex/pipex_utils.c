/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 18:59:42 by doreshev          #+#    #+#             */
/*   Updated: 2022/06/28 18:15:35 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_perror(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

int	ft_strncmp2(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	if (s1[i] == '\n')
		return (0);
	return (1);
}

int	ft_here_doc(char *argv)
{
	int		in;
	char	*s;

	in = open("hdoc.tmp", O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (in < 0)
		ft_perror(0);
	s = get_next_line(0);
	if (!s)
	{
		unlink("hdoc.tmp");
		exit(0);
	}
	while (ft_strncmp2(s, argv) && s)
	{
		write(in, s, ft_strlen(s));
		free(s);
		s = get_next_line(0);
	}
	free(s);
	close(in);
	return (1);
}

void	ft_cmd_free(char *tmp, char **tmp1)
{
	int	i;

	i = 0;
	if (tmp)
		free(tmp);
	if (!tmp1)
		return ;
	while (tmp1[i])
	{
		free(tmp1[i]);
		i++;
	}
	free(tmp1);
}

char	*ft_cmd_add(char *argv, char **envp)
{
	char	*new;
	char	*tmp;
	char	**tmp1;
	int		i;

	new = NULL;
	i = 0;
	while (ft_strncmp(*envp, "PATH=", 5) != 0 && envp)
		envp++;
	if (!envp)
		ft_perror(0);
	tmp1 = ft_split(*envp + 5, ':');
	tmp = ft_strjoin("/", *ft_split(argv, ' '));
	while (access(ft_strjoin(tmp1[i], tmp), F_OK) == -1 && tmp1)
		i++;
	if (tmp1[i])
		new = ft_strjoin(tmp1[i], tmp);
	ft_cmd_free(tmp, tmp1);
	return (new);
}
