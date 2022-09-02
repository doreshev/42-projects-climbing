/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 11:56:18 by doreshev          #+#    #+#             */
/*   Updated: 2022/07/25 17:38:21 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_lex_redirection(t_token *tmp, t_token *tmp2, t_data *a)
{
	if (!tmp2 || tmp2->c != 'W')
		return (ft_lexer_error(tmp2, a));
	tmp->content = tmp2->content;
	tmp->next = tmp2->next;
	free(tmp2);
	tmp2 = NULL;
	return (0);
}

int	ft_lex_pipe(t_token *tmp2, t_data *a)
{
	if (!tmp2 || tmp2->c == '|')
		return (ft_lexer_error(tmp2, a));
	return (0);
}

void	ft_lex_cmd(t_token *tmp, t_token *tmp2)
{
	char	*tmp3;

	while (tmp2 && tmp2->c == 'W')
	{
		tmp3 = ft_join_tokens(tmp->content, tmp2->content);
		free(tmp2->content);
		free(tmp->content);
		tmp->content = tmp3;
		tmp->next = tmp2->next;
		free(tmp2);
		tmp2 = tmp2->next;
	}
}

void	ft_lexer(t_data *a, int i)
{
	t_token	*tmp;
	t_token	*tmp2;

	tmp = a->token;
	if (tmp->c == '|')
		i = ft_lexer_error(tmp->next, a);
	while (tmp && i == 0)
	{
		tmp2 = tmp->next;
		if (tmp->c == '>' || tmp->c == 'H' || tmp->c == '<' || tmp->c == 'A')
			i = ft_lex_redirection(tmp, tmp2, a);
		else if (tmp->c == '|')
			i = ft_lex_pipe(tmp2, a);
		else
			ft_lex_cmd(tmp, tmp2);
		tmp = tmp->next;
	}
	if (i == 0)
		ft_execute(a, 0, a->token);
}
