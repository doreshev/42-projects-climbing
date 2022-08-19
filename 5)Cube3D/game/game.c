/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 12:22:25 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/19 12:43:28 by doreshev         ###   ########.fr       */
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
		write(2, "Error!\nImage file is missing or unavailable!\n", 45);
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
	if (a->player == 'E')
		a->diry = -1;
	else if (a->player == 'N' || a->player == 'S')
	{
		a->dirx = 0;
		a->diry = -1;
		if (a->player == 'N')
			a->diry = 1;
	}
}

void	ft_game(t_data *a)
{
	ft_check_map_init(a);
	a->mlx = mlx_init();
	ft_img_render(a);
	a->win = mlx_new_window(a->mlx, WIDTH, HEIGHT, "Cube3D");
	mlx_mouse_hide();
	mlx_hook(a->win, 17, 0, ft_close, a);
	mlx_key_hook(a->win, ft_key_hook, a);
	mlx_loop_hook(a->mlx, ft_game_start, a);
	mlx_loop(a->mlx);
}
