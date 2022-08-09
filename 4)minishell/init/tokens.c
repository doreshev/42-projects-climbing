/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:56:35 by doreshev          #+#    #+#             */
/*   Updated: 2022/07/22 18:23:29 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_token_quote(t_data *a, int i)
{
	int	j;

	j = 0;
	while (a->line[i + j] && a->line[i + j] != '\'')
		j++;
	if (!a->line[i + j])
	{
		a->exit_status = 258;
		ft_free(a, 1);
		write(2, "syntax error, missing '\n", 24);
		return (-1);
	}
	ft_new_token(a, 'W', ft_substr(a->line, i, j), 1);
	return (i + j + 1);
}

int	ft_token_dquote(t_data *a, int i)
{
	int	j;

	j = 0;
	while (a->line[i + j] && a->line[i + j] != '"')
	{
		if (a->line[i + j] == '$' && a->line[i + j + 1] != '"')
		{
			if (j)
				ft_new_token(a, 'W', ft_substr(a->line, i, j), 1);
			i = ft_token_dollar(a, i + j + 1, 0);
			j = -1;
		}
		j++;
	}
	if (!a->line[i + j])
	{
		a->exit_status = 258;
		ft_free(a, 1);
		write(2, "syntax error, missing \"\n", 24);
		return (-1);
	}
	ft_new_token(a, 'W', ft_substr(a->line, i, j), 1);
	return (i + j + 1);
}

int	ft_token_word(t_data *a, int i)
{
	if (a->line[i] == ' ' || a->line[i] == '\v' || a->line[i] == '\t')
	{
		ft_token_separate(a);
		while (a->line[i] == ' ' || a->line[i] == '\v' || a->line[i] == '\t')
			i++;
		return (i);
	}
	ft_new_token(a, 'W', ft_substr(a->line, i, 1), 1);
	return (i + 1);
}

int	ft_token_pipeline(t_data *a, int i)
{
	ft_token_separate(a);
	ft_new_token(a, '|', NULL, 0);
	return (i);
}

int	ft_token_redir(t_data *a, int i)
{
	ft_token_separate(a);
	if (a->line[i] == '<')
	{
		i++;
		if (a->line[i] == '<')
		{
			i++;
			ft_new_token(a, 'H', NULL, 0);
		}
		else
			ft_new_token(a, '<', NULL, 0);
	}
	else
	{
		i++;
		if (a->line[i] == '>')
		{
			i++;
			ft_new_token(a, 'A', NULL, 0);
		}
		else
			ft_new_token(a, '>', NULL, 0);
	}
	return (i);
}
