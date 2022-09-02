/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build-in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:54:35 by doreshev          #+#    #+#             */
/*   Updated: 2022/07/27 13:22:39 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	build_in_sub1(char *s, t_data *a, int k)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != ' ')
		i++;
	if (k != 0)
		ft_signals('3');
	if (a->in != 0)
		dup2(a->in, 0);
	if (a->out != 1)
		dup2(a->out, 1);
	return (i);
}

void	ft_build_in_sub2(char *tmp, t_data *a, int j)
{
	free(tmp);
	if (j != -1)
	{
		ft_free(a, 0);
		exit(j);
	}
}

int	check_build_in(char *s, t_data *a, int k)
{
	char	*tmp;
	int		i;
	int		j;

	j = -1;
	i = build_in_sub1(s, a, k);
	tmp = ft_substr(s, 0, i);
	if (!ft_strncmp(tmp, "echo", 4))
		ft_echo(s + 4, a);
	else if (!ft_strncmp(tmp, "cd", 2))
		ft_cd(s + 2, a, a->env);
	else if (!ft_strncmp(tmp, "pwd", 3))
		ft_pwd(a);
	else if (!ft_strncmp(tmp, "export", 6))
		ft_export(s + 6, a, a->env);
	else if (!ft_strncmp(tmp, "unset", 5))
		ft_unset(s + 5, a);
	else if (!ft_strncmp(tmp, "env", 3))
		ft_env(s + 3, a, a->env);
	else if (!ft_strncmp(tmp, "exit", 4))
		j = ft_exit(s + 4, k);
	else
		i = -1;
	ft_build_in_sub2(tmp, a, j);
	return (i);
}
