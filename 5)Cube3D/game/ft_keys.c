/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:43:18 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/20 16:31:23 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	w_key(t_data *a)
{
	// if (a->py > 1)
	// 	a->py -= 0.2;
	a->px += a->pdx;
	a->py += a->pdy;
}

void	s_key(t_data *a)
{
	// if (a->py < a->map_height)
	// 	a->py += 0.2;
	a->px -= a->pdx;
	a->py -= a->pdy;
}

void	d_key(t_data *a)
{
	// if (a->px < a->map_width)
	// 	a->px += 0.2;
	a->pa += 0.1;
	if (a->pa > 2 * PI)
		a->pa -= 2 * PI;
	a->pdx = cos(a->pa);
	a->pdy = sin(a->pa);
}

void	a_key(t_data *a)
{
	// if (a->px > 1)
	// 	a->px -= 0.2;
	a->pa -= 0.1;
	if (a->pa < 0)
		a->pa += 2 * PI;
	a->pdx = cos(a->pa);
	a->pdy = sin(a->pa);
}

int	ft_key_hook(int keycode, t_data *a)
{
	if (keycode == 53)
		ft_close(a);
	else if (keycode == 12)
	{
		if (a->mouse == '\0')
		{
			a->mouse = '1';
			mlx_mouse_show();
			return (0);
		}
		a->mouse = '\0';
		mlx_mouse_hide();
	}
	else if (keycode == 13)
		w_key(a);
	else if (keycode == 1)
		s_key(a);
	else if (keycode == 2)
		d_key(a);
	else if (keycode == 0)
		a_key(a);
	return (0);
}
