/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 17:25:14 by doreshev          #+#    #+#             */
/*   Updated: 2022/07/27 15:35:38 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_token(t_token *p)
{
	t_token	*tmp;

	while (p)
	{
		tmp = p;
		if (p->content)
			free(p->content);
		p->content = NULL;
		p = p->next;
		tmp->next = NULL;
		free(tmp);
	}
}

void	ft_free_env(t_env *p)
{
	t_env	*tmp;

	while (p)
	{
		tmp = p;
		if (p->content)
			free(p->content);
		p->content = NULL;
		free(p->key);
		p->key = NULL;
		p = p->next;
		tmp->next = NULL;
		free(tmp);
	}
}

void	ft_free(t_data *a, int i)
{
	if (a->line)
		free(a->line);
	a->line = NULL;
	if (i == 0 && a->env)
	{
		close(a->std[0]);
		close(a->std[1]);
		rl_on_new_line();
		rl_clear_history();
		a->env1 = NULL;
		a->argv0 = NULL;
		ft_free_env(a->env);
		a->env = NULL;
	}
	if (a->token)
		ft_free_token(a->token);
	a->token = NULL;
}
