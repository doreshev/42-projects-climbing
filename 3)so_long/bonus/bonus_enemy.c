/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_enemy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 13:48:04 by doreshev          #+#    #+#             */
/*   Updated: 2022/06/10 20:36:03 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

void	ft_wenemy(t_map *map, int i)
{
	int	x;

	if (map->steps % 2 == 0)
		ft_senemy(map, i);
	else
	{
		x = map->width;
		if (map->mapall[i - x] == 'P')
			ft_gameover(map);
		if (map->mapall[i - x] == '0')
		{
			map->mapall[i] = '0';
			map->mapall[i - x] = 'D';
		}
	}
}

void	ft_senemy(t_map *map, int i)
{
	int	x;

	if (map->steps % 2 != 0)
		ft_aenemy(map, i);
	else
	{
		x = map->width;
		if (map->mapall[i + x] == 'P')
			ft_gameover(map);
		if (map->mapall[i + x] == '0')
		{
			map->mapall[i] = '0';
			map->mapall[i + x] = 'D';
		}
	}
}

void	ft_denemy(t_map *map, int i)
{
	if (map->steps % 2 != 0)
		ft_wenemy(map, i);
	else
	{
		if (map->mapall[i + 1] == 'P')
			ft_gameover(map);
		if (map->mapall[i + 1] == '0')
		{
			map->mapall[i] = '0';
			map->mapall[i + 1] = 'D';
		}
	}
}

void	ft_aenemy(t_map *map, int i)
{
	if (map->steps % 2 == 0)
		ft_denemy(map, i);
	else
	{
		if (map->mapall[i - 1] == 'P')
			ft_gameover(map);
		if (map->mapall[i - 1] == '0')
		{
			map->mapall[i] = '0';
			map->mapall[i - 1] = 'D';
		}
	}
}

void	ft_enemy(t_map *map)
{
	int	i;

	i = 0;
	while (map->mapall[i])
	{
		if (map->mapall[i] == 'D')
		{
			if (map->players == 30 || map->players == 340)
			{
				ft_aenemy(map, i);
				i++;
			}
			else if (map->players == 90 || map->players == 240)
				ft_senemy(map, i);
			else if (map->players == 140 || map->players == 390)
				ft_wenemy(map, i);
			else if (map->players == 190 || map->players == 290)
			{
				ft_denemy(map, i);
				i++;
			}
		}
		i++;
	}
}
