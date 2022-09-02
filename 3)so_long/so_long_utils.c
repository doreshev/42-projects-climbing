/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 12:28:51 by doreshev          #+#    #+#             */
/*   Updated: 2022/06/08 18:15:52 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	ft_close(t_map *map)
{
	mlx_destroy_window(map->mlx, map->win);
	ft_free_lst(map);
	exit(EXIT_SUCCESS);
}
