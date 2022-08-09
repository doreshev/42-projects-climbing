/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_redir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 20:23:38 by doreshev          #+#    #+#             */
/*   Updated: 2022/07/27 16:09:23 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_check_permission(char *s, char c)
{
	int	i;

	i = -1;
	if (c == '<')
	{
		if (access(s, F_OK) == 0 && access(s, R_OK) == 0)
			i = open(s, O_RDONLY);
		else
			perror(s);
	}
	else
	{
		if (c == '>')
			i = open(s, O_RDWR | O_CREAT | O_TRUNC, 0644);
		else
			i = open(s, O_RDWR | O_CREAT | O_APPEND, 0644);
		if (access(s, F_OK) != 0
			|| (access(s, R_OK) != 0 && access(s, W_OK) != 0))
			perror(s);
	}
	return (i);
}

int	ft_here_doc_read(int i, t_data *a)
{
	char	*s;
	char	*tmp;

	tmp = ft_itoa(a->hd++);
	s = ft_strjoin("hdoc.tmp", tmp);
	free(tmp);
	if (i != -1 && access(s, F_OK) == 0 && access(s, R_OK) == 0)
		i = open(s, O_RDONLY);
	else if (i != -1)
		perror(s);
	unlink(s);
	free(s);
	return (i);
}

int	ft_sub_redir(t_token *tmp, t_data *a, int i)
{
	if (i != -1 && (tmp->c == '>' || tmp->c == 'A'))
	{
		if (a->out > 1)
			close(a->out);
		a->out = ft_check_permission(tmp->content, tmp->c);
	}
	else if (i != -1 && tmp->c == '<')
	{
		if (a->in > 0)
			close(a->in);
		a->in = ft_check_permission(tmp->content, tmp->c);
	}
	else if (tmp->c == 'H')
	{
		if (a->in > 0)
			close(a->in);
		a->in = ft_here_doc_read(i, a);
	}
	return (i);
}

t_token	*ft_exec_redir(t_data *a, t_token *tmp, int i, int j)
{
	t_token	*tmp2;

	tmp2 = NULL;
	while (tmp && tmp->c != '|')
	{
		i = ft_sub_redir(tmp, a, i);
		if (tmp->c == 'W' && !j)
		{
			j++;
			tmp2 = tmp;
		}
		if (!i && (a->in < 0 || a->out < 0))
		{
			i = -1;
			a->exit_status = 1;
		}
		if (tmp->c == '>' || tmp->c == 'H' || tmp->c == '<' || tmp->c == 'A')
			tmp = ft_delete_token(a, tmp, 0);
		else
			tmp = tmp->next;
	}
	return (tmp2);
}
