/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 16:29:49 by doreshev          #+#    #+#             */
/*   Updated: 2022/07/27 16:06:28 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*ft_execute_sub(t_data *a, t_token *tmp, int i)
{
	int	j;

	j = 0;
	a->in = 0;
	a->out = 1;
	ft_signals('1');
	tmp = ft_exec_redir(a, tmp, 0, 0);
	while (!j && tmp)
	{
		if (a->in > -1 && a->out > -1 && tmp->c == 'W')
			ft_exec(a, tmp, i);
		else if (tmp && tmp->c == '|')
			j = 1;
		tmp = tmp->next;
	}
	return (tmp);
}

void	ft_check_child_status(t_data *a, int i)
{
	if (a->pid >= 0)
	{
		waitpid(a->pid, &i, 0);
		if (WIFSIGNALED(i))
		{
			write(1, "\n", 1);
			a->exit_status = 128 + WTERMSIG(i);
		}
		else if (WIFEXITED(i))
			a->exit_status = WEXITSTATUS(i);
		while (wait(NULL) > 0)
			a->hd = 0;
	}
	dup2(a->std[0], 0);
	dup2(a->std[1], 1);
}

void	ft_execute(t_data *a, int i, t_token *tmp)
{
	while (tmp)
	{
		if (tmp->c == 'H')
			if (ft_here_doc_create(tmp->content, a, 0))
				return ;
		tmp = tmp->next;
	}
	a->hd = 0;
	tmp = a->token;
	while (tmp)
	{
		tmp = ft_execute_sub(a, tmp, i);
		i++;
	}
	ft_check_child_status(a, i);
}
