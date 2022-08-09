/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:00:49 by doreshev          #+#    #+#             */
/*   Updated: 2022/07/27 15:48:10 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env	*ft_new_env(char *s)
{
	t_env	*new;
	int		i;

	new = malloc(sizeof(t_env));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '=')
		i++;
	new->key = ft_substr(s, 0, i);
	new->content = ft_strdup(s + i + 1);
	new->next = NULL;
	return (new);
}

t_env	*ft_envcpy(char **envp)
{
	t_env	*env;
	t_env	*tmp;
	t_env	*tmp2;
	int		i;

	i = 0;
	env = NULL;
	tmp2 = NULL;
	while (envp[i])
	{
		tmp = ft_new_env(envp[i]);
		if (!tmp)
		{
			ft_free_env(env);
			write(2, "Error: failed to allocate memory!\n", 34);
			exit(EXIT_FAILURE);
		}
		if (!env)
			env = tmp;
		else
			tmp2->next = tmp;
		tmp2 = tmp;
		i++;
	}
	return (env);
}

void	ft_check_parameters(t_data *a, int i)
{
	while (i > -1 && a->line[i])
	{
		if (a->line[i] == '$')
			i = ft_token_dollar(a, i + 1, 0);
		else if (a->line[i] == '"')
			i = ft_token_dquote(a, i + 1);
		else if (a->line[i] == '\'')
			i = ft_token_quote(a, i + 1);
		else if (a->line[i] == '>' || a->line[i] == '<')
			i = ft_token_redir(a, i);
		else if (a->line[i] == '|')
			i = ft_token_pipeline(a, i + 1);
		else
			i = ft_token_word(a, i);
	}
}

void	ft_init_tokens(t_data *a, int in, int out)
{
	char	*tmp;

	tmp = ft_strtrim(a->line, " ");
	free(a->line);
	a->line = tmp;
	a->token = NULL;
	a->hd = 0;
	a->pid = -1;
	a->fd[0] = -1;
	a->fd[1] = -1;
	a->std[0] = in;
	a->std[1] = out;
	ft_check_parameters(a, 0);
}

void	ft_init(t_data *a)
{
	int	in;
	int	out;

	in = dup(0);
	out = dup(1);
	a->exit_status = 0;
	a->env = ft_envcpy(a->env1);
	a->line = NULL;
	while (in > 0 && out > 0)
	{
		ft_signals('0');
		a->line = readline("minishell > ");
		if (!a->line)
			return ;
		if (ft_strlen(a->line) > 0)
		{
			add_history(a->line);
			ft_init_tokens(a, in, out);
			if (a->token)
				ft_lexer(a, 0);
			ft_free(a, 1);
		}
	}
}
