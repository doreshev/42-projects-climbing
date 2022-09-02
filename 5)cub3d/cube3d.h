/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:29:19 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/31 19:09:12 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# define HEIGHT   1000
# define WIDTH    1000
# define KEYS     '0'

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
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
	double	px;
	double	py;
	double	rx;
	double	ry;
	int		side;
	int		sideh;
	double	atan_ra;
	double	tan_ra;
}				t_ray;

typedef struct s_sprite {
	double	x;
	double	y;
	double	z;
	double	sn;
	double	cs;
}				t_sprite;

typedef struct s_data {
	void	*mlx;
	void	*win;
	void	*img;
	void	*no;
	void	*so;
	void	*ea;
	void	*we;
	void	*minimap;
	void	*key;
	void	*key2;
	void	*door;
	char	*addr[9];
	int		bits_per_pixel[9];
	int		line_length[9];
	int		endian[9];
	int		c[3];
	int		f[3];
	char	*line;
	char	player;
	double	map_width;
	double	map_height;
	int		mouse_x;
	int		mouse_y;
	char	mouse;
	double	px;
	double	py;
	double	pdx;
	double	pdy;
	double	pa;
	double	dist;
	int		side;
	int		ray;
	double	stepy;
	int		linelen;
	char	key_num;
	int		d_x;
	int		d_y;
	int		step_num;
	char	open;
	char	sprite;
	double	s_px;
	double	s_py;
	double	spr_scale;
	double	t_x;
	double	t_y;
	double	t_x_st;
	double	t_y_st;
	double	b;
	double	sy;
	double	sx;
	double	angle;
	int		loop;
	char	anim;
	t_list	*map;
}				t_data;

void	ft_error(char *s, t_data *a);
void	ft_free(t_data *a);
int		ft_close(t_data *a);
void	ft_lstfree(t_list *map);

void	ft_map_process(t_data *a, char *argv);
void	ft_check_parameters(t_data *a, char *line, int fd);
void	ft_map_check(t_list	*tmp, t_data *a);
void	ft_map_init(char *line, t_data *a, int fd);

void	ft_minimap_render(t_list *map, t_data *a);
void	my_mlx_pixel_put_mini(t_data *a, int x, int y, int color);
void	sprite_init(t_data *a);
void	draw_sprite(t_data *a, int i);
int		ft_game_start(t_data *a);
void	ft_game(t_data *a);
int		ft_key_hook(int keycode, t_data *a);
void	ft_ray_cast(t_data *a, t_ray *ray);
void	ft_vertical_ray(t_data *a, t_ray *ray);
void	draw_line(t_data *a, int i);
char	get_map_symbol(int mx, int my, t_data *a);
void	put_map_symbol(int mx, int my, t_data *a, char c);
void	my_mlx_pixel_put(t_data *a, int x, int y, int color);
double	ft_distance(t_ray *ray);
double	degree_to_radian(double a);
double	fix_angle(double a);
void	left_key(t_data *a);
void	right_key(t_data *a);
void	e_key(t_data *a);
void	q_key(t_data *a);
void	ft_loop(t_data *a);

#endif