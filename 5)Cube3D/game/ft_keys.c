/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:43:18 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/22 18:08:11 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	w_key(t_data *a)
{
	if (get_map_symbol(a->px + a->pdx, a->py + a->pdy, a) == '0')
	{
		a->px += a->pdx;
		a->py += a->pdy;
	}
}

void	s_key(t_data *a)
{
	if (get_map_symbol(a->px - a->pdx, a->py - a->pdy, a) == '0')
	{
		a->px -= a->pdx;
		a->py -= a->pdy;
	}
}

void	d_key(t_data *a)
{
	a->pa += 0.1;
	if (a->pa > 2 * M_PI)
		a->pa -= 2 * M_PI;
	a->pdx = cos(a->pa);
	a->pdy = sin(a->pa);
}

void	a_key(t_data *a)
{
	a->pa -= 0.1;
	if (a->pa < 0)
		a->pa += 2 * M_PI;
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
