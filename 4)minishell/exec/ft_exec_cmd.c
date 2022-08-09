/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:51:05 by doreshev          #+#    #+#             */
/*   Updated: 2022/07/27 15:47:21 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_child_cmd_sub2(t_data *a, t_token *tmp)
{
	if (a->env && ft_cmd_add(tmp, a->env) != NULL)
	{
		if (execve(ft_cmd_add(tmp, a->env),
				ft_split(tmp->content, ' '), a->env1) == -1)
		{
			perror(tmp->content);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		write(2, tmp->content, ft_strlen(tmp->content));
		write(2, ": command not found\n", 20);
		exit(127);
	}
}

void	ft_child_cmd_sub(t_data *a, t_token *tmp)
{
	if (check_build_in(tmp->content, a, 1) != -1)
		exit(a->exit_status);
	if (ft_access(tmp->content) != -1)
	{
		if (execve(ft_cmdsub(tmp->content, 0),
				ft_split(ft_cmdsub(tmp->content, 1), ' '), a->env1) == -1)
		{
			perror(tmp->content);
			exit(EXIT_FAILURE);
		}
	}
	else
		ft_child_cmd_sub2(a, tmp);
	exit(0);
}

void	ft_child_cmd(t_data *a, t_token *tmp, int i)
{
	ft_signals('3');
	if (a->in != 0)
		dup2(a->in, 0);
	if (a->out != 1)
		dup2(a->out, 1);
	if (i)
	{
		close(a->fd[0]);
		if (a->out == 1 && i > 0)
			dup2(a->fd[1], 1);
		else if (a->out == 1 && i < 0)
			dup2(a->std[1], 1);
		close(a->fd[1]);
	}
	ft_check_dir(tmp->content, 0);
	ft_child_cmd_sub(a, tmp);
}

void	ft_exec_cmd(t_data *a, t_token *tmp, int i)
{
	a->pid = fork();
	if (a->pid < 0)
	{
		perror(0);
		ft_free(a, 1);
		return ;
	}
	if (a->pid == 0)
		ft_child_cmd(a, tmp, i);
	if (i)
	{
		close(a->fd[1]);
		if (i > 0)
			dup2(a->fd[0], 0);
		else
			dup2(a->std[0], 0);
		close(a->fd[0]);
	}
}

void	ft_exec(t_data *a, t_token *tmp, int i)
{
	t_token	*tmp2;
	int		k;

	tmp2 = tmp;
	k = -1;
	while (tmp2 && tmp2->c != '|')
		tmp2 = tmp2->next;
	if (tmp2)
		i++;
	else if (!tmp2 && i > 0)
		i = i * (-1);
	if (i > 0)
	{
		if (pipe(a->fd) == -1)
		{
			perror(0);
			ft_free(a, 1);
			return ;
		}
	}
	if (!i)
		k = check_build_in(tmp->content, a, 0);
	if (k == -1)
		ft_exec_cmd(a, tmp, i);
}
