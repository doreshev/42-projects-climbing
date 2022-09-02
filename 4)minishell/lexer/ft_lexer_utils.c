/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lexer_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 17:36:32 by doreshev          #+#    #+#             */
/*   Updated: 2022/07/22 18:23:49 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strlen2(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != ' ')
		i++;
	return (i);
}

int	ft_lexer_error(t_token *tmp2, t_data *a)
{
	a->exit_status = 258;
	write(2, "syntax error near unexpected token `", 36);
	if (tmp2)
	{
		if (tmp2->c == 'H')
			write(2, "<<", 2);
		else if (tmp2->c == 'A')
			write(2, ">>", 2);
		else if (tmp2->c == 'W')
			write(2, tmp2->content, ft_strlen2(tmp2->content));
		else
			write(2, &tmp2->c, 1);
	}
	else
		write(2, "newline", 7);
	write(2, "'\n", 2);
	return (-1);
}

char	*ft_join_tokens(char *s1, char *s2)
{
	char	*new;
	size_t	i;
	size_t	length;

	i = 0;
	if (!s1 && !s2)
		return (NULL);
	length = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(length + 2);
	if (!new)
		return (NULL);
	while (s1 && s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i++] = ' ';
	length = i;
	while (s2 && s2[i - length])
	{
		new[i] = s2[i - length];
		i++;
	}
	new[i] = '\0';
	return (new);
}
