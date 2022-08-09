/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd_exit_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 19:04:34 by doreshev          #+#    #+#             */
/*   Updated: 2022/07/27 10:57:07 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_pwd(t_data *a)
{
	char	*s;

	a->exit_status = 0;
	s = getcwd(NULL, 0);
	if (!s)
	{
		a->exit_status = 1;
		perror("pwd");
		return ;
	}
	ft_putstr_fd(s, 1);
	write(1, "\n", 1);
}

int	ft_exit_sub(char *s)
{
	int	i;

	i = 0;
	while (ft_isdigit(s[i]))
		i++;
	if (s[i])
	{
		write(2, "exit: ", 6);
		write(2, s, ft_strlen(s));
		write(2, ": numeric argument required\n", 28);
		return (255);
	}
	i = ft_atoi(s);
	return (i % 256);
}

int	ft_exit(char *s, int j)
{
	int	i;

	i = 0;
	if (j == 0)
		write(1, "exit\n", 5);
	if (!*s++)
		return (0);
	while (s[i] && s[i] != ' ')
		i++;
	if (s[i])
	{
		write(2, "exit: too many arguments\n", 25);
		return (255);
	}
	return (ft_exit_sub(s));
}

void	ft_env_sub(char *s, t_data *a)
{
	int			i;
	char		*tmp;
	struct stat	path_stat;

	i = 0;
	while (s[i] && s[i] != ' ')
		i++;
	tmp = ft_substr(s, 0, i);
	stat(tmp, &path_stat);
	if (S_ISDIR(path_stat.st_mode) || access(tmp, F_OK) == 0)
	{
		a->exit_status = 126;
		write(2, "env: ", 5);
		write(2, tmp, 5);
		write(2, ": Permission denied\n", 20);
	}
	else
	{
		a->exit_status = 127;
		write(2, "env: ", 5);
		write(2, tmp, 5);
		write(2, ": No such file or directory\n", 28);
	}
	free(tmp);
}

void	ft_env(char *s, t_data *a, t_env *env)
{
	a->exit_status = 0;
	if (*s++)
	{
		ft_env_sub(s, a);
		return ;
	}
	while (env)
	{
		if (env->key && env->content)
		{
			write(1, env->key, ft_strlen(env->key));
			write(1, "=", 1);
			write(1, env->content, ft_strlen(env->content));
			write(1, "\n", 1);
		}
		env = env->next;
	}
}
