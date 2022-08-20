/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 18:01:44 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/20 18:28:07 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

double ft_distance(double x1, double y1, double x2, double y2)
{
    double	dif_x;
    double	dif_y;
    double	sum;
    double	value;

	dif_x= (x2 - x1) * (x2 - x1);
	dif_y= (y2 - y1) * (y2 - y1);
	sum = dif_x + dif_y;
	value = sqrt(sum);
    return value;
}

void	ft_ray_sub(t_data *a, int dof, double xo, double yo)
{
	int	mx;
	int	my;
	int	mp;
	int	dist;

	while (dof < a->map_height)
	{
		mx = (int) a->rx >> 6;
		my = (int) a->ry >> 6;
		mp = my * (int) a->px + mx;
		if (mp < a->map_width * a->map_height && ft_hit_wall(my, mx))
		{
			dist = ft_distance(a->px, a->py, a->rx, a->ry);
			if (a->dist > dist)
				a->dist = dist;
			dof = a->map_height;
		}
		else
		{
			a->rx += xo;
			a->ry += yo;
			dof += 1;
		}
	}
}

void	ft_vertical_ray(t_data *a)
{
	double	xo;;
	double	yo;
	int		dof;

	dof = 0;
	if (a->pa < PI / 2 || a->pa > 3 / 2 * PI)
	{
		a->rx = (((int)a->px >> 6) << 6) + 64;
		a->ry = (a->px - a->rx) * (- tan(a->pa)) + a->py;
		xo = 64;
		yo = xo * tan(a->pa);
	}
	else if (a->pa > PI / 2 && a->pa < 3 / 2 * PI)
	{
		a->rx = (((int)a->py >> 6) << 6) - 0.0001;
		a->ry = (a->px - a->rx) * (- tan(a->pa)) + a->py;
		xo = -64;
		yo = xo * tan(a->pa);
	}
	else
	{
		dof = a->map_height;
		a->rx = a->px;
		a->ry = a->py;
	}
	ft_ray_sub(a, dof, xo, yo);
}

void	ft_ray_cast(t_data *a)
{
	double	xo;
	double	yo;
	int		dof;

	dof = 0;
	a->dist = 1e30;
	if (a->pa < PI)
	{
		a->ry = (((int)a->py >> 6) << 6) + 64;
		a->rx = (a->py - a->ry) * (-1 / tan(a->pa)) + a->px;
		yo = 64;
		xo = yo / tan(a->pa);
	}
	else if (a->pa > PI)
	{
		a->ry = (((int)a->py >> 6) << 6) - 0.0001;
		a->rx = (a->py - a->ry) * (-1 / tan(a->pa)) + a->px;
		yo = -64;
		xo = yo / tan(a->pa);
	}
	else
	{
		dof = a->map_height;
		a->rx = a->px;
		a->ry = a->py;
	}
	ft_ray_sub(a, dof, xo, yo);
	ft_vertical_ray(a);
}