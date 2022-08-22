/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 18:01:44 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/22 19:22:09 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_vertical_ray_sub(t_data *a, t_ray *ray)
{
	int	mx;
	int	my;
	int	dist;

	while (ray->dof < 8)
	{
		mx = (int) a->rx >> 6;
		my = (int) a->ry >> 6;
		printf("V: %i : %i\n", mx, my);
		if (get_map_symbol(mx, my, a) == '1')
		{
			dist = ft_distance(ray, a);
			if (a->dist > dist)
				a->dist = dist;
			else
			{
				a->rx = ray->hx;
				a->ry = ray->hy;
			}
			ray->dof = 8;
		}
		else
		{
			a->rx += ray->xo;
			a->ry += ray->yo;
			ray->dof += 1;
		}
	}
}

void	ft_horisontal_ray_sub(t_data *a, t_ray *ray)
{
	int		mx;
	int		my;

	while (ray->dof < 8)
	{
		mx = (int)a->rx >> 6;
		my = (int)a->ry >> 6;
		printf("H: %i : %i\n", mx, my);
		if (get_map_symbol(mx, my, a) == '1')
		{
			a->dist = ft_distance(ray, a);
			ray->hx = a->rx;
			ray->hy = a->ry;
			ray->dof = 8;
		}
		else
		{
			a->rx += ray->xo;
			a->ry += ray->yo;
			ray->dof += 1;
		}
	}
}

void	ft_vertical_ray(t_data *a, t_ray *ray)
{
	ray->dof = 0;
	ray->vx = a->px;
	ray->vy = a->py;
	if (ray->ra > M_PI_2 && ray->ra < 3 * M_PI_2)
	{
		a->rx = (((int)a->py >> 6) << 6) - 0.0001;
		a->ry = (a->px - a->rx) * (-1 * tan(ray->ra)) + a->py;
		ray->xo = -64;
		ray->yo = ray->xo * tan(ray->ra);
	}
	else if (ray->ra < M_PI_2 || ray->ra > 3 * M_PI_2)
	{
		a->rx = (((int)a->px >> 6) << 6) + 64;
		a->ry = (a->px - a->rx) * (-1 * tan(ray->ra)) + a->py;
		ray->xo = 64;
		ray->yo = ray->xo * tan(ray->ra);
	}
	else
	{
		ray->dof = 8;
		a->rx = a->px;
		a->ry = a->py;
	}
	ft_vertical_ray_sub(a, ray);
}

void	ft_horisontal_ray(t_data *a, t_ray *ray)
{
	ray->dof = 0;
	ray->hx = a->px;
	ray->hy = a->py;
	if (ray->ra > M_PI)
	{
		a->ry = (((int)a->py >> 6) << 6) - 0.0001;
		a->rx = (a->py - a->ry) * (-1 / tan(ray->ra)) + a->px;
		ray->yo = -64;
		ray->xo = ray->yo / tan(ray->ra);
	}
	else if (ray->ra < M_PI)
	{
		a->ry = (((int)a->py >> 6) << 6) + 64;
		a->rx = (a->py - a->ry) * (-1 / tan(ray->ra)) + a->px;
		ray->yo = 64;
		ray->xo = ray->yo / tan(ray->ra);
	}
	else
	{
		ray->dof = 8;
		a->rx = a->px;
		a->ry = a->py;
	}
	ft_horisontal_ray_sub(a, ray);
}

void	ft_ray_cast(t_data *a)
{
	t_ray	ray;
	int		i;

	ray.xo = 0;
	ray.yo = 0;
	ray.ra = a->pa - 30 * DR;
	if (ray.ra < 0)
		ray.ra += 2 * M_PI;
	else if (ray.ra > 2 * M_PI)
		ray.ra -= 2 * M_PI;
	i = 0;
	while (i < 60)
	{
		a->dist = 1000000;
		ft_horisontal_ray(a, &ray);
		ft_vertical_ray(a, &ray);
		remove_fisheye(&ray, a);
		draw_line(a, i);
		ray.ra += DR;
		if (ray.ra < 0)
			ray.ra += 2 * M_PI;
		else if (ray.ra > 2 * M_PI)
			ray.ra -= 2 * M_PI;
		i++;
	}
}
