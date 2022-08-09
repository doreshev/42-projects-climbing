/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:06:39 by doreshev          #+#    #+#             */
/*   Updated: 2022/07/25 11:21:01 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_token	*ft_delete_token(t_data *a, t_token *tmp, t_token *tmp2)
{
	if (a->token && tmp && a->token == tmp)
	{
		a->token = a->token->next;
		tmp2 = a->token;
		if (tmp->content)
			free(tmp->content);
		free(tmp);
	}
	else if (a->token && tmp)
	{
		tmp2 = a->token;
		while (tmp2 && tmp2->next != tmp)
			tmp2 = tmp2->next;
		if (tmp2)
		{
			tmp2->next = tmp->next;
			if (tmp->content)
				free(tmp->content);
			free(tmp);
			tmp2 = tmp2->next;
		}
	}
	return (tmp2);
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

char	*ft_cmd_add(t_token *tmp, t_env	*tmpe)
{
	char	*new;
	char	*tmp2;
	char	**tmp1;
	int		i;

	new = NULL;
	i = 0;
	while (tmpe && ft_strncmp(tmpe->key, "PATH", 4) != 0)
		tmpe = tmpe->next;
	if (!tmpe)
		return (NULL);
	tmp1 = ft_split(tmpe->content, ':');
	tmp2 = ft_strjoin("/", *ft_split(tmp->content, ' '));
	while (tmp1 && access(ft_strjoin(tmp1[i], tmp2), X_OK) == -1 && tmp1[i])
		i++;
	if (tmp1 && tmp1[i])
		new = ft_strjoin(tmp1[i], tmp2);
	ft_cmd_free(tmp2, tmp1);
	return (new);
}

char	*ft_cmdsub(char *tmp, int i)
{
	char	*s;

	s = NULL;
	if (!tmp)
		return (NULL);
	if (i == 0)
	{
		while (tmp[i] && tmp[i] != ' ')
			i++;
		if (!tmp[i])
			return (tmp);
		return (ft_substr(tmp, 0, i));
	}
	while (*tmp)
	{
		if (*tmp == '/')
			s = tmp;
		tmp++;
	}
	if (s && *s)
		s++;
	return (s);
}

int	ft_access(char *s)
{
	char	*tmp;
	int		i;

	if (!s)
		return (-1);
	i = 0;
	if (access(s, X_OK) != -1 && (s[i] == '.' || s[i] == '/'))
		return (0);
	while (s[i] && s[i] != ' ')
		i++;
	if (s[i])
	{
		tmp = ft_substr(s, 0, i);
		if (access(tmp, X_OK) != -1)
		{
			free(tmp);
			return (0);
		}
	}
	return (-1);
}
