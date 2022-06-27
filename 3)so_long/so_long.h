/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:26:45 by doreshev          #+#    #+#             */
/*   Updated: 2022/06/08 17:41:33 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

typedef struct s_map {
	int		width;
	int		height;
	int		players;
	int		gameover;
	int		steps;
	int		score;
	int		max_score;
	char	*mapall;
	void	*wall;
	void	*exit;
	void	*item;
	void	*player;
	void	*space;
	void	*mlx;
	void	*win;
}				t_map;

void	ft_free_lst(t_map *map);
void	ft_error(char *s, t_map *map);
void	ft_map_process(int fd, t_map *map);
void	ft_game(t_map *map);
void	ft_map_render(t_map *map, int i);
int		ft_close(t_map *map);
int		ft_key_hook(int keycode, t_map *map);

#endif