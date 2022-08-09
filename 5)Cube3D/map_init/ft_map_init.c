/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:02:47 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/06 14:44:31 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int	ft_map_line_check(char *line, t_data *a)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == 'N' || line[i] == 'S'
			|| line[i] == 'E' || line[i] == 'W')
		{
			if (a->player != '\0')
				ft_error("More than one players!\n", a);
			a->player = line[i];
			a->posx = i + 1;
			a->posy = a->map_height + 1;
		}
		else if (line[i] != ' ' && line[i] != '1' && line[i] != '0')
			ft_error("Invalid Map!\n", a);
		i++;
	}
	return (i);
}

void	ft_check_edges(char *s, t_data *a)
{
	int	i;

	i = 0;
	while (s[i] && s[i] == ' ')
		i++;
	if (s[i] != '1')
		ft_error("Invalid Map!\n", a);
	while (s[i] == ' ' || s[i] == '1')
		i++;
	if (s[i] && s[i] != '\n')
		ft_error("Invalid Map!\n", a);
}

void	ft_check_maplines(char *s, char *s2, char *s3, t_data *a)
{
	int	i;

	i = 0;
	while (s2[i] && s2[i] == ' ')
		i++;
	if (s2[i] != '1')
		ft_error("Invalid Map!\n", a);
	while (s2 && s2[i] && s2[i] != '\n')
	{
		while (s2[i] && (s2[i] == ' ' || s2[i] == '1'))
			i++;
		if (s2[i] && s2[i] != '\n')
		{
			if (s2[i - 1] == ' ' || s2[i + 1] == ' ' || !s2[i + 1]
				|| s2[i + 1] == '\n' || s[i + 1] == '\n' || !s[i + 1]
				|| s[i - 1] == ' ' || s[i + 1] == ' ' || s[i] == ' '
				|| s3[i - 1] == ' ' || s3[i + 1] == ' ' || s3[i] == ' '
				|| s3[i + 1] == '\n' || !s3[i + 1])
				ft_error("Invalid Map!\n", a);
			i++;
		}
	}
}

void	ft_map_check(t_list	*tmp, t_data *a)
{
	t_list	*tmp2;
	t_list	*tmp3;

	tmp2 = tmp->next;
	if (!tmp2)
		ft_error("Invalid Map!\n", a);
	tmp3 = tmp2->next;
	while (tmp2)
	{
		if (tmp == a->map)
			ft_check_edges(tmp->content, a);
		if (tmp3 == NULL)
		{
			ft_check_edges(tmp2->content, a);
			return ;
		}
		ft_check_maplines(tmp->content, tmp2->content, tmp3->content, a);
		tmp = tmp->next;
		tmp2 = tmp2->next;
		tmp3 = tmp3->next;
	}
}

void	ft_map_init(char *line, t_data *a, int fd)
{
	int		i;

	if (a->player == '\n')
		ft_error("Player position not found!", a);
	while (line)
	{
		i = 0;
		while (line[i] && line[i] == ' ')
			i++;
		if (!line[i] || line[i] == '\n')
		{
			free(line);
			a->line = NULL;
			break ;
		}
		i = ft_map_line_check(line, a);
		if (i > a->map_width)
			a->map_width = i;
		ft_lstadd_back(&a->map, ft_lstnew(ft_strtrim(line, "\n")));
		free(line);
		a->line = NULL;
		line = get_next_line(fd);
		a->map_height++;
	}
	ft_map_check(a->map, a);
}
