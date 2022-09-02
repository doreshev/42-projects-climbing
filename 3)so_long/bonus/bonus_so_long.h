/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_so_long.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:26:45 by doreshev          #+#    #+#             */
/*   Updated: 2022/06/10 20:33:34 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_SO_LONG_H
# define BONUS_SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

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
	void	*item0;
	void	*item1;
	void	*item2;
	void	*player;
	void	*player0;
	void	*player1;
	void	*player2;
	void	*playerw;
	void	*player_s;
	void	*playerd;
	void	*playera;
	void	*space;
	void	*mlx;
	void	*win;
	void	*enemy;
	void	*enemy0;
	void	*enemy1;
	void	*enemy2;
	void	*gameov;
}				t_map;

void	ft_aenemy(t_map *map, int i);
void	ft_senemy(t_map *map, int i);
void	ft_enemy(t_map *map);
void	ft_gameover(t_map *map);
void	ft_put_enemy(t_map *map);
void	ft_free_lst(t_map *map);
void	ft_error(char *s, t_map *map);
void	ft_map_process(int fd, t_map *map);
int		ft_game(t_map *map);
void	ft_img_render(t_map *map);
void	ft_map_render(t_map *map, int i, int x, int y);
void	ft_gameover(t_map *map);
int		ft_close(t_map *map);
int		ft_key_hook(int keycode, t_map *map);

#endif