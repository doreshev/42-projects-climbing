/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_cd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:05:09 by doreshev          #+#    #+#             */
/*   Updated: 2022/07/27 12:16:38 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_echo(char *s, t_data *a)
{
	int	i;
	int	flag;

	a->exit_status = 0;
	flag = 0;
	if (s && *s == ' ')
		s++;
	while (s[0] && s[0] == '-' && s[1] == 'n')
	{
		i = 1;
		while (*s && s[i] == 'n')
			i++;
		if (s[i] == ' ' || !s[i])
		{
			flag = 1;
			if (s[i])
				i += 1;
			s += i;
		}
		else
			break ;
	}
	ft_putstr_fd(s, 1);
	if (flag == 0)
		write(1, "\n", 1);
}

void	ft_cd_change_env(t_env *new, t_env *old)
{
	if (!new)
	{
		if (old)
		{
			if (old->content)
				free(old->content);
			old->content = NULL;
		}
		return ;
	}
	else
	{
		if (old)
		{
			if (old->content)
				free(old->content);
			old->content = new->content;
		}
		if (!old && new->content)
			free(new->content);
		new->content = getcwd(NULL, 0);
	}
}

void	ft_cd_sub1(char *s, t_data *a, t_env *new)
{
	t_env	*old;

	old = new;
	if (chdir(s) != 0)
	{
		a->exit_status = 1;
		perror(s);
		return ;
	}
	while (old && ft_strncmp("OLDPWD", old->key, 6))
		old = old->next;
	while (new && ft_strncmp("PWD", new->key, 6))
		new = new->next;
	ft_cd_change_env(new, old);
}

void	ft_cd(char *s, t_data *a, t_env *env)
{
	a->exit_status = 0;
	if (!s || *s == '\0')
	{
		while (env && ft_strncmp(env->key, "HOME", 4))
			env = env->next;
		if (env == NULL)
		{
			a->exit_status = 1;
			write(2, "cd: HOME not set\n", 17);
		}
		else
		{
			if (chdir(env->content) != 0)
			{
				perror("cd");
				a->exit_status = 1;
			}
		}
	}
	else
	{
		s++;
		ft_cd_sub1(s, a, env);
	}
}
