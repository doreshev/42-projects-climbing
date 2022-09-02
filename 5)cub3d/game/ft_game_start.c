/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:28:26 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/31 19:09:18 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_map_render(t_data *a)
{
	t_ray		ray;

	if (a->img)
		mlx_destroy_image(a->mlx, a->img);
	a->img = mlx_new_image(a->mlx, WIDTH, HEIGHT);
	if (!a->img)
	{
		write(2, "Error\nImage creation failed!\n", 29);
		ft_close(a);
	}
	a->addr[1] = mlx_get_data_addr(a->img, &a->bits_per_pixel[1],
			&a->line_length[1], &a->endian[1]);
	sprite_init(a);
	ft_ray_cast(a, &ray);
	mlx_put_image_to_window(a->mlx, a->win, a->img, 0, 0);
}

int	ft_game_start(t_data *a)
{
	int	x;

	ft_loop(a);
	ft_map_render(a);
	ft_minimap_render(a->map, a);
	x = a->mouse_x;
	mlx_mouse_get_pos(a->win, &a->mouse_x, &a->mouse_y);
	if (a->mouse_x > x)
		right_key(a);
	else if (a->mouse_x < x)
		left_key(a);
	if (a->open == '1' && a->step_num > 15
		&& ((int)a->px != a->d_x || (int)a->py != a->d_y))
		put_map_symbol(a->d_x, a->d_y, a, 'D');
	return (0);
}
