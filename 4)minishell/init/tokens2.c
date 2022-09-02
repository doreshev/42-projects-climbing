/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 19:35:10 by doreshev          #+#    #+#             */
/*   Updated: 2022/07/27 13:58:25 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	check_next_token(t_data *a, char b)
{
	t_token	*tmp;
	t_token	*tmp2;

	tmp = a->token;
	tmp2 = NULL;
	if (tmp)
		tmp2 = tmp->next;
	while (tmp2 && tmp2->next)
	{
		tmp = tmp->next;
		tmp2 = tmp->next;
	}
	if (!tmp2 || (tmp2 && tmp2->i == 1))
		tmp2 = tmp;
	if (tmp2 && tmp2->c == b)
		return (1);
	return (0);
}

char	*ft_token_dollar_sub(t_data *a, int i, int j)
{
	char	*tmp;
	t_env	*tmp2;

	if (!a->env)
		return (NULL);
	tmp = ft_substr(a->line, i, j);
	tmp2 = a->env;
	while (tmp2)
	{
		if (!ft_strncmp(tmp, tmp2->key, 0))
		{
			free(tmp);
			return (ft_strdup(tmp2->content));
		}
		tmp2 = tmp2->next;
	}
	free(tmp);
	return (NULL);
}

int	ft_token_dollar(t_data *a, int i, int j)
{
	if (!a->line[i] || ft_check_symbol(a->line[i]) > 2 || a->line[i] == '$'
		|| check_next_token(a, 'H'))
	{
		ft_new_token(a, 'W', ft_substr(a->line, i - 1, 1), 1);
		return (i);
	}
	if (a->line[i] == '?' || ft_isdigit(a->line[i]))
	{
		if (a->line[i] == '?')
			ft_new_token(a, 'W', ft_itoa(a->exit_status), 1);
		else
			if (a->line[i] == '0')
				ft_new_token(a, 'W', ft_strdup(a->argv0), 1);
		i++;
		return (i);
	}
	while (ft_check_symbol(a->line[i + j]) == 0 && a->line[i + j] != '$')
		j++;
	ft_new_token(a, 'W', ft_token_dollar_sub(a, i, j), 1);
	return (i + j);
}
