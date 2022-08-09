/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 13:13:59 by amathew           #+#    #+#             */
/*   Updated: 2022/07/27 12:39:33 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_delete_in_env_sub(char *s, t_env *env)
{
	t_env	*tmp;

	tmp = env->next;
	while (tmp && ft_strncmp(s, tmp->key, 0))
	{
		tmp = tmp->next;
		env = env->next;
	}
	if (tmp)
	{
		env->next = tmp->next;
		free(tmp->content);
		free(tmp->key);
		free(tmp);
	}
}

void	ft_delete_in_env(char *s, t_env *env, t_data *a)
{
	int		i;

	i = 0;
	if (!env)
		return ;
	if (ft_strncmp(s, env->key, 0) == 0)
	{
		a->env = a->env->next;
		free(env->content);
		free(env->key);
		free(env);
		return ;
	}
	ft_delete_in_env_sub(s, env);
}

void	ft_exp_uns_sub(char *s, t_data *a, char c, int i)
{
	char	*tmp;

	while (*s)
	{
		if (!ft_isalpha(s[0]) && s[0] != '_')
		{
			write(2, "export: ", 8);
			write(2, s, ft_strlen(s));
			write(2, ": not a valid identifier\n", 25);
			a->exit_status = 1;
			return ;
		}
		while (s[i] && s[i] != ' ')
			i++;
		tmp = ft_substr(s, 0, i);
		if (c == '0')
			ft_put_in_env(tmp, a->env, a);
		else
			ft_delete_in_env(tmp, a->env, a);
		free(tmp);
		if (s[i] == ' ')
			i++;
		s += i;
	}
}

void	ft_unset(char *s, t_data *a)
{
	a->exit_status = 0;
	if (!s || *s == '\0')
		return ;
	s++;
	ft_exp_uns_sub(s, a, '1', 0);
}
