/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_v.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 13:31:17 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/31 13:48:24 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_vertical_dist_check(t_data *a, t_ray *ray, char c)
{
	a->dist = ft_distance(ray);
	a->side = ray->side;
	if (c == 'D')
		a->side = 6;
	ray->dof = a->map_width;
}

void	ft_vertical_ray_sub(t_data *a, t_ray *ray)
{
	int		mx;
	int		my;
	char	c;

	while (ray->dof < a->map_width)
	{
		mx = (int)ray->rx >> 6;
		my = (int)ray->ry >> 6;
		c = get_map_symbol(mx, my, a);
		if (c == '1' || c == 'D')
			ft_vertical_dist_check(a, ray, c);
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof += 1;
		}
	}
	ray->vx = ray->rx;
	ray->vy = ray->ry;
}

void	ft_vertical_ray(t_data *a, t_ray *ray)
{
	ray->tan_ra = tan(degree_to_radian(ray->ra));
	ray->dof = 0;
	if (cos(degree_to_radian(ray->ra)) > 0.0001)
	{
		ray->side = 5;
		ray->rx = (((int)ray->px >> 6) << 6) + 64;
		ray->ry = (ray->px - ray->rx) * ray->tan_ra + ray->py;
		ray->xo = 64;
		ray->yo = -64 * ray->tan_ra;
	}
	else if (cos(degree_to_radian(ray->ra)) < -0.001)
	{
		ray->side = 4;
		ray->rx = (((int)ray->px >> 6) << 6) - 0.001;
		ray->ry = (ray->px - ray->rx) * ray->tan_ra + ray->py;
		ray->xo = -64;
		ray->yo = 64 * ray->tan_ra;
	}
	else
	{
		ray->dof = a->map_width;
		ray->rx = ray->px;
		ray->ry = ray->py;
	}
	ft_vertical_ray_sub(a, ray);
}
