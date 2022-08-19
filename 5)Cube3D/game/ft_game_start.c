/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:28:26 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/19 18:08:56 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	my_mlx_pixel_put(t_data *a, int x, int y, int color)
{
	char	*dst;

	dst = a->addr + ((y * a->line_length1) + x * (a->bits_per_pixel1 / 8));
	*(unsigned int *)dst = color;
}

void	ft_ray_casting(t_list *map, t_data *a)
{
	
}

void	ft_map_render(t_list *map, t_data *a)
{
	if (a->img)
		mlx_destroy_image(a->mlx, a->img);
	a->img = mlx_new_image(a->mlx, WIDTH, HEIGHT);
	a->addr = mlx_get_data_addr(a->img, &a->bits_per_pixel1,
			&a->line_length1, &a->endian1);
	ft_ray_casting(map, a);
	mlx_put_image_to_window(a->mlx, a->win, a->minimap, 0, 0);
}

int	ft_game_start(t_data *a)
{
	mlx_mouse_get_pos(a->win, &a->mouse_x, &a->mouse_y);
	ft_map_render(a->map, a);
	ft_minimap_render(a->map, a);
	return (0);
}
