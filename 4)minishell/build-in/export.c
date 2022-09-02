/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 12:23:46 by doreshev          #+#    #+#             */
/*   Updated: 2022/07/27 12:37:45 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_put_in_env_sub(char *tmp1, char *tmp2, t_env *env, int j)
{
	if (!ft_strncmp(tmp1, env->key, 0))
	{
		if (!j)
			return ;
		free(tmp1);
		free(env->content);
		env->content = tmp2;
	}
	else
	{
		env->next = malloc(sizeof(t_env));
		env = env->next;
		env->key = tmp1;
		env->content = tmp2;
		env->next = NULL;
	}
}

void	ft_put_in_env(char *s, t_env *env, t_data *a)
{
	int		i;
	int		j;
	char	*tmp1;
	char	*tmp2;

	i = 0;
	j = 0;
	tmp2 = NULL;
	tmp1 = NULL;
	while (s[i] && s[i] != '=')
		i++;
	tmp1 = ft_substr(s, 0, i);
	if (s[i] == '=' && !j++)
		tmp2 = ft_substr(s, i + 1, ft_strlen(s) - i - 1);
	while (env && env->next && ft_strncmp(tmp1, env->key, 0))
		env = env->next;
	if (!env)
	{
		a->env = malloc(sizeof(t_env));
		a->env->key = tmp1;
		a->env->content = tmp2;
		a->env->next = NULL;
	}
	else
		ft_put_in_env_sub(tmp1, tmp2, env, j);
}

void	ft_export(char *s, t_data *a, t_env *env)
{
	a->exit_status = 0;
	if (!s || *s == '\0')
	{
		while (env)
		{
			write(1, "declare -x ", 11);
			write(1, env->key, ft_strlen(env->key));
			if (env->content)
			{
				write(1, "=\"", 2);
				write(1, env->content, ft_strlen(env->content));
				write(1, "\"", 1);
			}
			write(1, "\n", 1);
			env = env->next;
		}
	}
	else
	{
		s++;
		ft_exp_uns_sub(s, a, '0', 0);
	}
}
