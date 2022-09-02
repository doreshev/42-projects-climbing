/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:30:22 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/31 15:54:12 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_wall_minimap(t_data *a, int x, int y, int k)
{
	int	j;
	int	i;

	i = 0;
	while (i <= WIDTH / 50)
	{
		j = 0;
		while (j <= HEIGHT / 50)
		{
			if (i == 0 || j == 0)
				my_mlx_pixel_put_mini(a, i + x * WIDTH / 50,
					j + y * HEIGHT / 50, 0x0FF000000);
			else
				my_mlx_pixel_put_mini(a, i + x * WIDTH / 50,
					j + y * HEIGHT / 50, k);
			j++;
		}
		i++;
	}
}

void	ft_player_minimap(t_data *a, double x, double y)
{
	double	j;
	double	i;

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

void	ft_player_init(t_data *a)
{
	double	x;
	double	y;

	if (a->px < 5)
		x = a->px;
	else if (a->map_width - a->px < 5)
		x = 10 - (a->map_width - a->px);
	else
		x = 4 + (a->px - (int)a->px);
	if (a->py < 5)
		y = a->py;
	else if (a->map_height - a->py < 5)
		y = 10 - (a->map_height - a->py);
	else
		y = 5 + (a->py - (int)a->py);
	ft_player_minimap(a, x, y);
}

void	ft_sub_minimap(t_list *map, t_data *a, double x)
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
				ft_wall_minimap(a, i, j, 0x9A228B22);
			else if (line[(int)x + i] == 'D')
				ft_wall_minimap(a, i, j, 0x9A966F33);
			else
				ft_wall_minimap(a, i, j, 0xFF000000);
			i++;
		}
		j++;
		map = map->next;
	}
	ft_player_init(a);
}

void	ft_minimap_render(t_list *map, t_data *a)
{
	double	y;
	double	x;

	if (a->minimap)
		mlx_destroy_image(a->mlx, a->minimap);
	a->minimap = mlx_new_image(a->mlx, WIDTH / 5, HEIGHT / 5);
	a->addr[1] = mlx_get_data_addr(a->minimap, &a->bits_per_pixel[0],
			&a->line_length[0], &a->endian[0]);
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
	ft_sub_minimap(map, a, x);
	mlx_put_image_to_window(a->mlx, a->win, a->minimap, 0, 0);
}
