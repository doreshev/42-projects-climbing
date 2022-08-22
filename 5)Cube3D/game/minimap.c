/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:30:22 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/22 18:01:44 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	my_mlx_pixel_put_mini(t_data *a, int x, int y, int color)
{
	char	*dst;

	dst = a->line + ((y * a->line_length) + x * (a->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_wall_minimap(t_data *a, int x, int y, int k)
{
	int	j;
	int	i;

	i = 1;
	while (i < WIDTH / 50)
	{
		j = 1;
		while (j < HEIGHT / 50)
		{
			my_mlx_pixel_put_mini(a, i + x * WIDTH / 50,
				j + y * HEIGHT / 50, k);
			j++;
		}
		i++;
	}
}

void	ft_player_minimap(t_data *a, float x, float y)
{
	float	j;
	float	i;

	if (a->py < 5)
		y = a->py;
	else if (a->map_height - a->py < 5)
		y = 10 - (a->map_height - a->py);
	else
		y = 5 + (a->py - (int)a->py);
	i = 0.5 - WIDTH / 250;
	while (i <= WIDTH / 250)
	{
		j = 0.5 - HEIGHT / 250;
		while (j <= WIDTH / 250)
		{
			my_mlx_pixel_put_mini(a, i + x * WIDTH / 50,
				j + y * HEIGHT / 50, 0x00FF0000);
			j++;
		}
		i++;
	}
}

void	ft_sub_minimap(t_list *map, t_data *a, float x, float y)
{
	int		i;
	int		j;
	char	*line;

	j = 0;
	while (map && j < 10)
	{
		line = map->content;
		i = 0;
		while (line[(int)x + i] && i < 10)
		{
			if (line[(int)x + i] == '1')
				ft_wall_minimap(a, i, j, 0x00228B22);
			i++;
		}
		j++;
		map = map->next;
	}
	if (a->px < 5)
		x = a->px;
	else if (a->map_width - a->px < 5)
		x = 10 - (a->map_width - a->px);
	else
		x = 4 + (a->px - (int)a->px);
	ft_player_minimap(a, x, y);
}

void	ft_minimap_render(t_list *map, t_data *a)
{
	float	y;
	float	x;

	if (a->minimap)
		mlx_destroy_image(a->mlx, a->minimap);
	a->minimap = mlx_new_image(a->mlx, WIDTH / 5, HEIGHT / 5);
	a->line = mlx_get_data_addr(a->minimap, &a->bits_per_pixel,
			&a->line_length, &a->endian);
	y = 0;
	while (a->map_height > 11 && a->py > y + 6 && a->map_height > y + 10)
	{
		map = map->next;
		y++;
	}
	if (a->map_width < 11 || a->px <= 4)
		x = 0;
	else if (a->map_width - a->px <= 6)
		x = a->map_width - 10;
	else
		x = a->px - 4;
	ft_sub_minimap(map, a, x, y);
	mlx_put_image_to_window(a->mlx, a->win, a->minimap, 0, 0);
}
