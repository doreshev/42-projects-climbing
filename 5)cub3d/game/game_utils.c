/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 10:57:54 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/31 13:21:26 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

double	degree_to_radian(double a)
{
	return (a * M_PI / 180.0);
}

double	fix_angle(double a)
{
	if (a > 359)
		a -= 360;
	else if (a < 0)
		a += 360;
	return (a);
}

double	ft_distance(t_ray *ray)
{
	return (cos(degree_to_radian(ray->ra)) * (ray->rx - ray->px)
		- sin(degree_to_radian(ray->ra)) * (ray->ry - ray->py));
}

void	put_map_symbol(int mx, int my, t_data *a, char c)
{
	t_list	*map;
	char	*s;

	if (mx < 0 || my < 0)
		return ;
	map = a->map;
	while (my > 0)
	{
		map = map->next;
		my--;
	}
	s = map->content;
	s[mx] = c;
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
