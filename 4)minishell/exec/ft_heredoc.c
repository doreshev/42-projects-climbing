/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 19:01:19 by doreshev          #+#    #+#             */
/*   Updated: 2022/07/27 20:53:43 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_heredoc_child(int in, char *s2)
{
	char	*s;

	ft_signals('2');
	s = readline("> ");
	if (s)
	{
		while (ft_strncmp(s, s2, 0) && s)
		{
			write(in, s, ft_strlen(s));
			write(in, "\n", 1);
			free(s);
			s = readline("> ");
		}
		if (s)
			free(s);
	}
	exit(0);
}

int	ft_here_doc_create(char *s2, t_data *a, int in)
{
	pid_t	pid;
	char	*s;
	char	*s3;

	s3 = ft_itoa(a->hd++);
	s = ft_strjoin("hdoc.tmp", s3);
	free(s3);
	in = open(s, O_RDWR | O_CREAT | O_TRUNC, 0644);
	free(s);
	if (in < 0)
		return (in);
	ft_signals('1');
	pid = fork();
	if (pid < 0)
	{
		perror(0);
		ft_free(a, 1);
		return (-1);
	}
	if (pid == 0)
		ft_heredoc_child(in, s2);
	waitpid(pid, 0, 0);
	close(in);
	ft_signals('0');
	return (0);
}

void	ft_check_dir_sub(char *s, int i)
{
	struct stat	path_stat;

	stat(s, &path_stat);
	if (S_ISDIR(path_stat.st_mode))
	{
		write(2, s, ft_strlen(s));
		write(2, ": is a directory\n", 17);
		if (i < 0)
			free(s);
		exit(126);
	}
	else if (!S_ISREG(path_stat.st_mode))
	{
		perror(s);
		if (i < 0)
			free(s);
		exit(127);
	}
	if (i < 0)
		free (s);
}

void	ft_check_dir(char *s, int i)
{
	if (*s == '.' || *s == '/')
	{
		if (s[1] == '.' && s[2] == '\0')
		{
			write(2, s, ft_strlen(s));
			write(2, ": command not found\n", 20);
			exit(127);
		}
		else if (!s[1])
		{
			write(2, ".: usage: . filename [arguments]\n", 33);
			exit(2);
		}
		while (s[i] && s[i] != ' ')
			i++;
		if (s[i])
		{
			s = ft_substr(s, 0, i);
			i = -1;
		}
		ft_check_dir_sub(s, i);
	}
}
