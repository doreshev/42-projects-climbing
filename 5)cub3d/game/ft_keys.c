/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:43:18 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/31 13:01:26 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	w_key(t_data *a)
{
	int		my;
	int		mx;
	char	c;

	mx = a->px + a->pdx * 0.3;
	my = a->py + a->pdy * 0.3;
	c = get_map_symbol(mx, my, a);
	if (c == '0' || c == 'K')
	{
		if (c == 'K')
		{
			a->key_num = '1';
			a->sprite = '0';
			put_map_symbol(mx, my, a, '0');
		}
		a->px += a->pdx * 0.2;
		a->py += a->pdy * 0.2;
		if (a->step_num)
			a->step_num++;
	}
}

void	s_key(t_data *a)
{
	int		my;
	int		mx;
	char	c;

	mx = a->px - a->pdx * 0.3;
	my = a->py - a->pdy * 0.3;
	c = get_map_symbol(mx, my, a);
	if (c == '0' || c == 'K')
	{
		if (c == 'K')
		{
			a->key_num = '1';
			a->sprite = '0';
			put_map_symbol(mx, my, a, '0');
		}
		a->px -= a->pdx * 0.2;
		a->py -= a->pdy * 0.2;
		if (a->step_num)
			a->step_num++;
	}
}

void	a_key(t_data *a)
{
	int		my;
	int		mx;
	char	c;

	mx = a->px + a->pdy * 0.3;
	my = a->py - a->pdx * 0.3;
	c = get_map_symbol(mx, my, a);
	if (c == '0' || c == 'K')
	{
		if (c == 'K')
		{
			a->key_num = '1';
			a->sprite = '0';
			put_map_symbol(mx, my, a, '0');
		}
		a->px += a->pdy * 0.2;
		a->py -= a->pdx * 0.2;
		if (a->step_num)
			a->step_num++;
	}
}

void	d_key(t_data *a)
{
	int		my;
	int		mx;
	char	c;

	mx = a->px - a->pdy * 0.3;
	my = a->py + a->pdx * 0.3;
	c = get_map_symbol(mx, my, a);
	if (c == '0' || c == 'K')
	{
		if (c == 'K')
		{
			a->key_num = '1';
			a->sprite = '0';
			put_map_symbol(mx, my, a, '0');
		}
		a->px -= a->pdy * 0.2;
		a->py += a->pdx * 0.2;
		if (a->step_num)
			a->step_num++;
	}
}

int	ft_key_hook(int keycode, t_data *a)
{
	if (keycode == 53)
		ft_close(a);
	else if (keycode == 12)
		q_key(a);
	else if (keycode == 13)
		w_key(a);
	else if (keycode == 1)
		s_key(a);
	else if (keycode == 2)
		d_key(a);
	else if (keycode == 0)
		a_key(a);
	else if (keycode == 14)
		e_key(a);
	else if (keycode == 123)
		left_key(a);
	else if (keycode == 124)
		right_key(a);
	return (0);
}
