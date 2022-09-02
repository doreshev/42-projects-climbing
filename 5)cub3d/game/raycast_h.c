/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_h.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 12:01:00 by y doreshev        #+#    #+#             */
/*   Updated: 2022/08/31 13:55:24 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_horisontal_dist_check(t_data *a, t_ray *ray, char c)
{
	double	disth;

	disth = ft_distance(ray);
	if (disth < a->dist)
	{
		a->side = ray->sideh;
		if (c == 'D')
			a->side = 6;
		a->dist = disth;
	}
	else
	{
		ray->rx = ray->vx;
		ray->ry = ray->vy;
	}
	ray->dof = a->map_height;
}

void	ft_horisontal_ray_sub(t_data *a, t_ray *ray)
{
	int		mx;
	int		my;
	char	c;

	while (ray->dof < a->map_height)
	{
		mx = (int)ray->rx >> 6;
		my = (int)ray->ry >> 6;
		c = get_map_symbol(mx, my, a);
		if (c == '1' || c == 'D')
			ft_horisontal_dist_check(a, ray, c);
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof += 1;
		}
	}
}

void	ft_horisontal_ray(t_data *a, t_ray *ray)
{
	ray->atan_ra = 1.0 / tan(degree_to_radian(ray->ra));
	ray->dof = 0;
	if (sin(degree_to_radian(ray->ra)) > 0.001)
	{
		ray->sideh = 2;
		ray->ry = (((int)ray->py >> 6) << 6) - 0.001;
		ray->rx = (ray->py - ray->ry) * ray->atan_ra + ray->px;
		ray->yo = -64;
		ray->xo = 64 * ray->atan_ra;
	}
	else if (sin(degree_to_radian(ray->ra)) < -0.001)
	{
		ray->sideh = 3;
		ray->ry = (((int)ray->py >> 6) << 6) + 64;
		ray->rx = (ray->py - ray->ry) * ray->atan_ra + ray->px;
		ray->yo = 64;
		ray->xo = -64 * ray->atan_ra;
	}
	else
	{
		ray->dof = a->map_height;
		ray->rx = ray->px;
		ray->ry = ray->py;
	}
	ft_horisontal_ray_sub(a, ray);
}

void	ft_ray_cast(t_data *a, t_ray *ray)
{
	int		i;

	ray->ra = fix_angle(a->pa + 30);
	i = 0;
	ray->px = a->px * 64;
	ray->py = a->py * 64;
	while (i < WIDTH)
	{
		a->dist = 1000000;
		ft_vertical_ray(a, ray);
		ft_horisontal_ray(a, ray);
		a->dist = a->dist * cos(degree_to_radian(fix_angle(a->pa - ray->ra)));
		if (a->side > 3 && a->side != 6)
			a->ray = (int)(ray->vy) % 64;
		else
			a->ray = (int)(ray->rx) % 64;
		draw_line(a, i);
		draw_sprite(a, i);
		ray->ra = fix_angle(ray->ra - a->angle);
		i++;
	}
}
