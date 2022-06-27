/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_so_long_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:28:51 by doreshev          #+#    #+#             */
/*   Updated: 2022/06/10 19:27:17 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_so_long.h"

int	ft_close(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	ft_free_lst(map);
	exit(EXIT_SUCCESS);
}

void	ft_free_lst(t_map *map)
{
	free(map->mapall);
	if (map->mlx)
		free(map->mlx);
}

void	ft_error(char *s, t_map *map)
{
	if (map->mapall)
		free(map->mapall);
	write(1, "Error\n", 6);
	ft_putstr_fd(s, 1);
	exit(EXIT_FAILURE);
}

void	ft_gameover(t_map *map)
{
	map->player = map->gameov;
	map->gameover++;
}

void	ft_put_enemy(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (map->mapall[i])
	{
		if (map->mapall[i] == '0')
			j++;
		if (j && j % 16 == 0)
		{
			j++;
			map->mapall[i] = 'D';
		}
		i++;
	}
}
