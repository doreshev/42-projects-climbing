/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:14:05 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/31 19:13:23 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	put_sprite_pixel(t_data *a, int x, int y)
{
	char	*dst;
	int		i;
	int		j;

	i = (int)a->t_x;
	j = (int)a->t_y;
	if (a->anim == '0')
		dst = a->addr[7] + ((j * a->line_length[7])
				+ i * (a->bits_per_pixel[7] / 8));
	else
		dst = a->addr[8] + ((j * a->line_length[8])
				+ i * (a->bits_per_pixel[8] / 8));
	if (*(unsigned int *)dst != 0x000FF00FF)
		my_mlx_pixel_put(a, x, y, *(unsigned int *)dst);
}

void	sprite_init(t_data *a)
{
	t_sprite	spr;

	if (a->sprite == '0')
		return ;
	a->sx = (a->s_px - a->px) * 64;
	a->sy = (a->s_py - a->py) * 64;
	spr.z = 10;
	spr.cs = cos(degree_to_radian(a->pa));
	spr.sn = sin(degree_to_radian(a->pa));
	spr.x = a->sy * spr.cs + a->sx * spr.sn;
	spr.y = a->sx * spr.cs - a->sy * spr.sn;
	a->b = spr.y;
	a->sx = spr.x * 864.0 / spr.y + (WIDTH / 2);
	a->sy = spr.z * 864.0 / spr.y + (HEIGHT / 2);
	a->spr_scale = 8 * HEIGHT / a->b;
	if (a->spr_scale < 0)
		a->spr_scale = 0;
	else if (a->spr_scale > WIDTH / 2)
		a->spr_scale = WIDTH / 2;
	a->t_x = 0;
	a->t_x_st = 63.0 / a->spr_scale;
	a->t_y_st = 64.0 / a->spr_scale;
}

void	draw_sprite(t_data *a, int i)
{
	double	y;

	if (a->sprite == '0')
		return ;
	if (i >= (a->sx - a->spr_scale / 2) && i < (a->sx + a->spr_scale / 2)
		&& a->b > 0 && a->b < a->dist)
	{
		a->t_y = 62;
		y = 0;
		while (y < a->spr_scale)
		{
			put_sprite_pixel(a, i, a->sy - y);
			a->t_y -= a->t_y_st;
			if (a->t_y < 0)
				a->t_y = 0;
			y++;
		}
		a->t_x += a->t_x_st;
	}
}
