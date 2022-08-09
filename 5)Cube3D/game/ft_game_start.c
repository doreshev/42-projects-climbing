/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_game_start.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 14:28:26 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/06 17:22:58 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

int	ft_game_start(t_data *a)
{
	mlx_mouse_get_pos(a->win, &a->mouse_x, &a->mouse_y);
	printf("x:%i  y:%i\n", a->mouse_x, a->mouse_y);
	//ft_map_render(a, 0);
	return (0);
}
