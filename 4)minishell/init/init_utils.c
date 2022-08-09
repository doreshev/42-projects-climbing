/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 18:22:28 by doreshev          #+#    #+#             */
/*   Updated: 2022/07/18 10:43:17 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_new_token_sub(t_data *a, char c, char *s, int i)
{
	t_token	*new;
	t_token	*tmp;

	if (!s && c == 'W')
		return ;
	new = malloc(sizeof(t_token));
	if (!new)
	{
		ft_free(a, 0);
		write(2, "Error: failed to allocate memory!\n", 34);
		exit(EXIT_FAILURE);
	}
	new->i = i;
	new->c = c;
	new->content = s;
	new->next = NULL;
	if (!a->token)
		a->token = new;
	else
	{
		tmp = a->token;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_new_token(t_data *a, char c, char *s, int i)
{
	char	*tmp;
	t_token	*tmp2;

	if (!a->token)
		ft_new_token_sub(a, c, s, i);
	else
	{
		tmp2 = a->token;
		while (tmp2->next)
			tmp2 = tmp2->next;
		if (tmp2->i == 0)
			ft_new_token_sub(a, c, s, i);
		else
		{
			tmp = ft_strjoin(tmp2->content, s);
			if (tmp2->content)
				free(tmp2->content);
			if (s)
				free(s);
			tmp2->content = tmp;
		}
	}
}

int	ft_check_symbol(char c)
{
	if (c == '\'')
		return (1);
	if (c == '"')
		return (2);
	if (c == '\0')
		return (3);
	if (c == ' ' || c == '\t' || c == '\v')
		return (4);
	if (c == '>')
		return (5);
	if (c == '<')
		return (6);
	if (c == '|')
		return (7);
	return (0);
}

void	ft_token_separate(t_data *a)
{
	t_token	*tmp;

	tmp = a->token;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->i = 0;
	}
}
