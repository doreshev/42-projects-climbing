/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 13:28:48 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/31 19:29:34 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	right_key(t_data *a)
{
	a->pa -= 5;
	a->pa = fix_angle(a->pa);
	a->pdx = cos(degree_to_radian(a->pa));
	a->pdy = -1 * sin(degree_to_radian(a->pa));
}

void	left_key(t_data *a)
{
	a->pa += 5;
	a->pa = fix_angle(a->pa);
	a->pdx = cos(degree_to_radian(a->pa));
	a->pdy = -1 * sin(degree_to_radian(a->pa));
}

void	e_key(t_data *a)
{
	int		my;
	int		mx;

	mx = a->px + a->pdx * 0.5;
	my = a->py + a->pdy * 0.5;
	if (get_map_symbol(mx, my, a) == 'D' && a->key_num == '1')
	{
		if (a->open == '1')
			put_map_symbol(a->d_x, a->d_y, a, 'D');
		a->d_x = mx;
		a->d_y = my;
		put_map_symbol(mx, my, a, '0');
		a->open = '1';
		a->step_num = 1;
	}
	else if (mx == a->d_x && my == a->d_y && a->key_num == '1'
		&& ((int)a->px != a->d_x || (int)a->py != a->d_y))
	{
		if (a->open == '1')
		{
			a->open = '0';
			put_map_symbol(mx, my, a, 'D');
		}
	}
}

void	q_key(t_data *a)
{
	if (a->mouse == '\0')
	{
		a->mouse = '1';
		mlx_mouse_show();
		return ;
	}
	a->mouse = '\0';
	mlx_mouse_hide();
}
