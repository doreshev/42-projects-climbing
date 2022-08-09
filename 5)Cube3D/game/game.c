/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:22:25 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/06 17:23:10 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cube3d.h"

void	ft_img_render(t_data *a)
{
	int		i;
	char	*tmp;

	i = 100;
	tmp = a->no;
	a->no = mlx_xpm_file_to_image(a->mlx, a->no, &i, &i);
	free(tmp);
	tmp = a->so;
	a->so = mlx_xpm_file_to_image(a->mlx, a->so, &i, &i);
	free(tmp);
	tmp = a->we;
	a->we = mlx_xpm_file_to_image(a->mlx, a->we, &i, &i);
	free(tmp);
	tmp = a->ea;
	a->ea = mlx_xpm_file_to_image(a->mlx, a->ea, &i, &i);
	free(tmp);
	if (!a->ea || !a->so || !a->we || !a->no)
	{
		ft_putstr_fd("Error!\nImage file is missing or unavailable!\n", 2);
		ft_lstfree(a->map);
		free(a->mlx);
		exit(EXIT_FAILURE);
	}
}

void	ft_check_map_init(t_data *a)
{
	if (a->no == NULL)
		ft_error("Texture 'NO' not found!\n", a);
	if (a->ea == NULL)
		ft_error("Texture 'EA' not found!\n", a);
	if (a->we == NULL)
		ft_error("Texture 'WE' not found!\n", a);
	if (a->so == NULL)
		ft_error("Texture 'SO' not found!\n", a);
	if (a->c[0] < 0)
		ft_error("Ceiling colour not found!\n", a);
	if (a->f[0] < 0)
		ft_error("Floor colour not found!\n", a);
	if (!a->map)
		ft_error("Map not found!\n", a);
	if (a->player == '\0')
		ft_error("Player position not found!\n", a);
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
	// else if (keycode == 13)
	// 	ft_wkey(map);
	// else if (keycode == 1)
	// 	ft_skey(map);
	// else if (keycode == 2)
	// 	ft_dkey(map);
	// else if (keycode == 0)
	// 	ft_akey(map);
	// if (map->gameover > 0)
	// 	ft_close(map);
	// mlx_clear_window(map->mlx, map->win);
	// ft_map_render(map, 0);
	return (0);
}

void	ft_game(t_data *a)
{
	ft_check_map_init(a);
	a->mlx = mlx_init();
	ft_img_render(a);
	a->win = mlx_new_window(a->mlx, WIDTH, HEIGHT, "Cube3D");
	//ft_map_render(a, 0);
	mlx_mouse_hide();
	mlx_hook(a->win, 17, 0, ft_close, a);
	mlx_key_hook(a->win, ft_key_hook, a);
	mlx_loop_hook(a->mlx, ft_game_start, a);
	mlx_loop(a->mlx);
}
