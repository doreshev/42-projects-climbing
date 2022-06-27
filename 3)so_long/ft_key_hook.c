/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:12:00 by doreshev          #+#    #+#             */
/*   Updated: 2022/06/08 18:18:24 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_wkey(t_map *map)
{
	int	x;
	int	i;

	x = map->width;
	i = 0;
	while (map->mapall[i] != 'P')
		i++;
	if (map->mapall[i - x] == 'E' && map->max_score == map->score)
	{
		map->gameover++;
		map->steps++;
		ft_printf("Moves: %i\n", map->steps);
	}
	if (map->mapall[i - x] != '1' && map->mapall[i - x] != 'E')
	{
		if (map->mapall[i - x] == 'C')
			map->score++;
		map->mapall[i] = '0';
		map->mapall[i - x] = 'P';
		map->steps++;
		ft_printf("Moves: %i\n", map->steps);
	}
}

void	ft_skey(t_map *map)
{
	int	x;
	int	i;

	x = map->width;
	i = 0;
	while (map->mapall[i] != 'P')
		i++;
	if (map->mapall[i + x] == 'E' && map->max_score == map->score)
	{
		map->gameover++;
		map->steps++;
		ft_printf("Moves: %i\n", map->steps);
	}
	if (map->mapall[i + x] != '1' && map->mapall[i + x] != 'E')
	{
		if (map->mapall[i + x] == 'C')
			map->score++;
		map->mapall[i] = '0';
		map->mapall[i + x] = 'P';
		map->steps++;
		ft_printf("Moves: %i\n", map->steps);
	}
}

void	ft_dkey(t_map *map)
{
	int	i;

	i = 0;
	while (map->mapall[i] != 'P')
		i++;
	if (map->mapall[i + 1] == 'E' && map->max_score == map->score)
	{
		map->gameover++;
		map->steps++;
		ft_printf("Moves: %i\n", map->steps);
	}
	if (map->mapall[i + 1] != '1' && map->mapall[i + 1] != 'E')
	{
		if (map->mapall[i + 1] == 'C')
			map->score++;
		map->mapall[i] = '0';
		map->mapall[i + 1] = 'P';
		map->steps++;
		ft_printf("Moves: %i\n", map->steps);
	}
}

void	ft_akey(t_map *map)
{
	int	i;

	i = 0;
	while (map->mapall[i] != 'P')
		i++;
	if (map->mapall[i - 1] == 'E' && map->max_score == map->score)
	{
		map->gameover++;
		map->steps++;
		ft_printf("Moves: %i\n", map->steps);
	}
	if (map->mapall[i - 1] != '1' && map->mapall[i - 1] != 'E')
	{
		if (map->mapall[i - 1] == 'C')
			map->score++;
		map->mapall[i] = '0';
		map->mapall[i - 1] = 'P';
		map->steps++;
		ft_printf("Moves: %i\n", map->steps);
	}
}

int	ft_key_hook(int keycode, t_map *map)
{
	if (keycode == 53)
		map->gameover++;
	else if (keycode == 13)
		ft_wkey(map);
	else if (keycode == 1)
		ft_skey(map);
	else if (keycode == 2)
		ft_dkey(map);
	else if (keycode == 0)
		ft_akey(map);
	if (map->gameover > 0)
		ft_close(map);
	mlx_clear_window(map->mlx, map->win);
	ft_map_render(map, 0);
	return (0);
}
