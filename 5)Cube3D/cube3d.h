/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:29:19 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/22 19:08:32 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# define WIDTH 1000
# define HEIGHT 1000
# define DR 0.0174533

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

typedef struct s_ray {
	int		dof;
	double	xo;
	double	yo;
	double	ra;
	double	hx;
	double	hy;
	double	vx;
	double	vy;
}				t_ray;

typedef struct s_data {
	void	*no;
	void	*ea;
	void	*we;
	void	*so;
	void	*minimap;
	void	*img;
	char	*addr;
	double	map_width;
	double	map_height;
	char	player;
	t_list	*map;
	int		c[3];
	int		f[3];
	char	*line;
	void	*mlx;
	void	*win;
	int		mouse_x;
	int		mouse_y;
	char	mouse;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		bits_per_pixel1;
	int		line_length1;
	int		endian1;
	double	px;
	double	py;
	double	pdx;
	double	pdy;
	double	pa;
	double	rx;
	double	ry;
	double	dist;
}				t_data;

void	ft_error(char *s, t_data *a);
void	ft_free(t_data *a);
int		ft_close(t_data *a);
void	ft_lstfree(t_list *map);

void	ft_map_process(t_data *a, char *argv);
void	ft_check_parameters(t_data *a, char *line, int fd);
void	ft_map_init(char *line, t_data *a, int fd);

int		ft_game_start(t_data *a);
void	ft_game(t_data *a);
int		ft_key_hook(int keycode, t_data *a);
void	ft_minimap_render(t_list *map, t_data *a);
void	ft_ray_cast(t_data *a);
void	draw_line(t_data *a, int i);
char	get_map_symbol(int	mx, int my, t_data *a);
double	ft_distance(t_ray *ray, t_data *a);
void	remove_fisheye(t_ray *ray, t_data *a);

#endif