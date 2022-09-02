/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:45:23 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/31 16:17:00 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	add_rows_to_map(t_data *a)
{
	char	*tmp;
	int		i;

	while (a->map_height < 10)
	{
		i = 0;
		tmp = malloc(a->map_width + 1);
		while (i < a->map_width)
		{
			tmp[i] = ' ';
			i++;
		}
		tmp[i] = '\0';
		ft_lstadd_back(&a->map, ft_lstnew(tmp));
		a->map_height++;
	}
}

void	put_spaces_if_not_rect(t_list *map, t_data *a)
{
	char	*tmp;

	if (a->map_width < 10)
		a->map_width = 10;
	while (map)
	{
		while ((int)ft_strlen(map->content) < a->map_width)
		{
			tmp = map->content;
			map->content = ft_strjoin(map->content, " ");
			free(tmp);
		}
		map = map->next;
	}
	if (a->map_height < 10)
		add_rows_to_map(a);
}

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
				ft_error("More than one player!\n", a);
			a->player = line[i];
			a->px = i + 0.5;
			a->py = a->map_height + 0.5;
			line[i] = '0';
		}
		else if (line[i] != ' ' && line[i] != '1' && line[i] != '0')
			ft_error("Invalid Map!\n", a);
		i++;
	}
	return (i);
}

void	ft_map_init(char *line, t_data *a, int fd)
{
	int		i;

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
	put_spaces_if_not_rect(a->map, a);
}

void	ft_map_process(t_data *a, char *argv)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_error("No such file or directory!\n", a);
	a->line = get_next_line(fd);
	if (!a->line)
		ft_error("Invalid map!\n", a);
	while (a->line)
	{
		ft_check_parameters(a, a->line, fd);
		if (!a->line)
			break ;
		free(a->line);
		a->line = get_next_line(fd);
	}
	close(fd);
	if (a->map == NULL)
		ft_error("Map pattern not found in file!\n", a);
}
