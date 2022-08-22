/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 13:42:37 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/22 19:20:42 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

double	ft_distance(t_ray *ray, t_data *a)
{
	return (cos(M_PI / 180.0 * (ray->ra)) * (a->rx - a->px) 
		- sin(M_PI / 180.0 * (ray->ra)) * (a->rx - a->py));
}

void	my_mlx_pixel_put(t_data *a, int x, int y, int color)
{
	char	*dst;

	dst = a->addr + ((y * a->line_length1) + x * (a->bits_per_pixel1 / 8));
	*(unsigned int *)dst = color;
}

char	get_map_symbol(int mx, int my, t_data *a)
{
	t_list	*map;
	char	*s;

	if (mx < 0 || my < 0 || mx >= a->map_width || my >= a->map_height)
		return (' ');
	map = a->map;
	while (my > 0)
	{
		map = map->next;
		my--;
	}
	s = map->content;
	return (s[mx]);
}

void	remove_fisheye(t_ray *ray, t_data *a)
{
	float	ang;
	
	ang = a->pa - ray->ra;
	if (ang > 2 * M_PI)
		ray->ra -= 2 * M_PI;
	else if (ang < 0)
		ang += 2 * M_PI;
	a->dist = a->dist * cos(ang);
}

void	draw_line(t_data *a, int i)
{
	int	lineh;
	int	y;
	int	x;

	lineh = (32 * HEIGHT) / a->dist;
	if (lineh > HEIGHT)
		lineh = HEIGHT;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x <= WIDTH / 60)
		{
			if (y < (HEIGHT - lineh) / 2)
				my_mlx_pixel_put(a, x + i * WIDTH / 60, y, 0x00FFFF00);
			else if (y > lineh + (HEIGHT - lineh) / 2)
				my_mlx_pixel_put(a, x + i * WIDTH / 60, y, 0x0000FFFF);
			else
				my_mlx_pixel_put(a, x + i * WIDTH / 60, y, 0x00FF0000);
			x++;
		}
		y++;
	}
}