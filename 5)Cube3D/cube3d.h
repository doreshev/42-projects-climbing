/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/29 12:29:19 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/06 18:10:22 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# define WIDTH 1920
# define HEIGHT 1200

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct s_data {
	void	*no;
	void	*ea;
	void	*we;
	void	*so;
	int		map_width;
	int		map_height;
	char	player;
	t_list	*map;
	int		c[3];
	int		f[3];
	int		posx;
	int		posy;
	char	*line;
	void	*mlx;
	void	*win;
	int		mouse_x;
	int		mouse_y;
	char	mouse;
}				t_data;

void	ft_error(char *s, t_data *a);
void	ft_free(t_data *a);
int		ft_close(t_data *a);
void	ft_lstfree(t_list *map);

void	ft_map_process(t_data *a, char *argv);
void	ft_check_parameters(t_data *a, char *line, int fd);
void	ft_map_init(char *line, t_data *a, int fd);

void	ft_game(t_data *a);
int		ft_key_hook(int keycode, t_data *a);
int		ft_game_start(t_data *a);

#endif