/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:58:19 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/31 18:47:08 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_textures_init(t_data *a, char *line, char c)
{
	char	*tmp;

	if ((c == 'N' && a->no) || (c == 'S' && a->so)
		|| (c == 'W' && a->we) || (c == 'E' && a->ea))
		ft_error("Multiple texture pathes for one instance!\n", a);
	tmp = ft_strtrim(line, "\n");
	if (c == 'N')
		a->no = ft_strtrim(tmp, " ");
	else if (c == 'S')
		a->so = ft_strtrim(tmp, " ");
	else if (c == 'W')
		a->we = ft_strtrim(tmp, " ");
	else
		a->ea = ft_strtrim(tmp, " ");
	free(tmp);
}

int	ft_f_c_colours_sub(char *line, int j, t_data *a)
{
	int	i;

	i = 0;
	while (line[i] && line[i] != ','
		&& (ft_isdigit(line[i]) || line[i] == ' ' || line[i] == '\t'))
		i++;
	if (j < 2 && line[i] != ',')
		ft_error("Invalid colour value\n", a);
	if (j == 2 && line[i] && line[i] != '\n'
		&& line[i] != ' ' && line[i] != '\t')
		ft_error("Invalid colour value\n", a);
	return (i);
}

void	ft_f_c_colours(t_data *a, char *line, char c)
{
	int		i;
	char	*tmp;
	int		j;

	j = 0;
	while (line && (*line == ' ' || *line == '\t'))
		line++;
	while (j < 3)
	{
		i = ft_f_c_colours_sub(line, j, a);
		tmp = ft_substr(line, 0, i);
		if (line[i] == ',')
			line++;
		line = line + i;
		i = ft_atoi(tmp);
		free(tmp);
		if (i > 255 || i < 0)
			ft_error("Invalid colour value\n", a);
		if (c == 'C')
			a->c[j] = i;
		else
			a->f[j] = i;
		j++;
	}
}

void	ft_check_parameters(t_data *a, char *line, int fd)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O')
		ft_textures_init(a, line + 2, 'N');
	else if (line[i] == 'S' && line[i + 1] == 'O')
		ft_textures_init(a, line + 2, 'S');
	else if (line[i] == 'W' && line[i + 1] == 'E')
		ft_textures_init(a, line + i + 2, 'W');
	else if (line[i] == 'E' && line[i + 1] == 'A')
		ft_textures_init(a, line + i + 2, 'E');
	else if (line[i] == 'F')
		ft_f_c_colours(a, line + i + 1, 'F');
	else if (line[i] == 'C')
		ft_f_c_colours(a, line + i + 1, 'C');
	else if (line[i] == '1')
		ft_map_init(line, a, fd);
	else if (line[i] && line[i] != '\n')
		ft_error("Invalid map!\n", a);
}
