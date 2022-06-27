/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 12:57:46 by doreshev          #+#    #+#             */
/*   Updated: 2022/06/01 15:58:32 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_child(char *argv, char **envp, int *fd)
{
	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	if (!ft_cmd_add(argv, envp))
		ft_perror(0);
	if (execve(ft_cmd_add(argv, envp),
			ft_split(argv, ' '), envp) == -1)
		ft_perror(0);
	exit(0);
}

void	ft_child_last(int argc, char **argv, char **envp, int i)
{
	int	out;

	if (!ft_strncmp(argv[1], "here_doc", 9))
		out = open(argv[argc - 1], O_RDWR | O_CREAT | O_APPEND, 0644);
	else
		out = open(argv[argc - 1], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (out < 0)
		ft_perror(0);
	dup2(out, 1);
	close(out);
	if (!ft_cmd_add(argv[i + 2], envp))
		ft_perror(0);
	if (execve(ft_cmd_add(argv[i + 2], envp),
			ft_split(argv[i + 2], ' '), envp) == -1)
		ft_perror(0);
	exit(0);
}

void	ft_parent(int argc, int *fd, int pid, int i)
{
	int	status;

	close(fd[1]);
	waitpid(pid, &status, 0);
	if (status)
	{
		write(1, "Error: Command not found!\n", 26);
		exit(127);
	}	
	if (i != argc - 4)
		dup2(fd[0], 0);
	close(fd[0]);
}

void	ft_pipe(int argc, char **argv, char **envp, int i)
{
	pid_t	pid;
	int		fd[2];

	while (i < argc - 3)
	{
		if (pipe(fd) == -1)
			ft_perror(0);
		pid = fork();
		if (pid < 0)
			ft_perror(0);
		if (pid == 0)
		{
			if (i != argc - 4)
				ft_child(argv[i + 2], envp, fd);
			else
			{
				close(fd[0]);
				close(fd[1]);
				ft_child_last(argc, argv, envp, i);
			}
		}
		else
			ft_parent(argc, fd, pid, i);
		i++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	in;
	int	i;

	if (argc > 4)
	{
		if (!ft_strncmp(argv[1], "here_doc", 9))
		{
			i = ft_here_doc(argv[2]);
			in = open("hdoc.tmp", O_RDONLY);
			dup2(in, 0);
			close(in);
			unlink("hdoc.tmp");
		}
		else
		{
			in = open(argv[1], O_RDONLY);
			i = 0;
		}
		if (in < 0)
			ft_perror(0);
		dup2(in, 0);
		close(in);
		ft_pipe(argc, argv, envp, i);
	}
	return (0);
}
