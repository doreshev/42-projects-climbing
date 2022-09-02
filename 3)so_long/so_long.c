/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:26:36 by doreshev          #+#    #+#             */
/*   Updated: 2022/06/08 18:19:05 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_initialize(t_map *map)
{
	map->width = 0;
	map->height = 0;
	map->players = 0;
	map->gameover = 0;
	map->steps = 0;
	map->score = 0;
	map->max_score = 0;
	map->mapall = NULL;
	map->wall = NULL;
	map->exit = NULL;
	map->item = NULL;
	map->player = NULL;
	map->space = NULL;
	map->mlx = NULL;
	map->win = NULL;
}

int	ft_check_format(char *s, char *s2)
{
	int	i;

	i = 0;
	while (ft_strlen(s) != 4 && s)
		s++;
	if (!s || *s == '\0')
		return (0);
	while (s[i])
	{
		if (s[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_map	map;

	ft_map_initialize(&map);
	if (argc == 2)
	{
		if (!ft_check_format(argv[1], ".ber"))
			ft_error("Wrong map format!\n", &map);
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
			ft_error("No such file or directory!\n", &map);
		ft_map_process(fd, &map);
		ft_game(&map);
	}
	ft_error("Invalid input!\n", &map);
	return (0);
}
