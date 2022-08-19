/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:28:26 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/19 17:13:02 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_ray_casting(t_list *map, t_data *a)
{
	
}

void	ft_map_render(t_list *map, t_data *a)
{
	ft_ray_casting(map, a);
}

int	ft_game_start(t_data *a)
{
	mlx_mouse_get_pos(a->win, &a->mouse_x, &a->mouse_y);
	// printf("x:%i, y:%i\n", a->mouse_x, a->mouse_y);
	ft_map_render(a->map, a);
	ft_minimap_render(a->map, a);
	return (0);
}
