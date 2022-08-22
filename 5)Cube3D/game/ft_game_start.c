/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:28:26 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/22 18:39:59 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_map_render(t_data *a)
{
	if (a->img)
		mlx_destroy_image(a->mlx, a->img);
	a->img = mlx_new_image(a->mlx, WIDTH, HEIGHT);
	a->addr = mlx_get_data_addr(a->img, &a->bits_per_pixel1,
			&a->line_length1, &a->endian1);
	ft_ray_cast(a);
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
}

int	ft_game_start(t_data *a)
{
	//mlx_mouse_get_pos(a->win, &a->mouse_x, &a->mouse_y);
	ft_map_render(a);
	ft_minimap_render(a->map, a);
	return (0);
}
