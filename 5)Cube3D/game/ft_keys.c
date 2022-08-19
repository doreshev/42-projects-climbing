/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 12:43:18 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/19 15:02:05 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

// void	w_key(t_data *a)
// {
	
// }

// void	a_key(t_data *a)
// {
	
// }

// void	s_key(t_data *a)
// {
	
// }

// void	d_key(t_data *a)
// {
	
// }

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
	// else if (keycode == 13)
	// 	ft_wkey(a);
	// else if (keycode == 1)
	// 	ft_skey(a);
	// else if (keycode == 2)
	// 	ft_dkey(a);
	// else if (keycode == 0)
	// 	ft_akey(a);
	return (0);
}
