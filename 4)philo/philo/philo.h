/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:11:13 by doreshev          #+#    #+#             */
/*   Updated: 2022/09/29 15:08:21 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_data
{
	int				phn;
	int				tot_ph;
	int				t2d;
	int				t2e;
	int				t2s;
	int				t2em;
	int				*die;
	int				*done;
	pthread_t		*tid;
	pthread_mutex_t	*done_eat;
	pthread_mutex_t	*fork_l;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*in;
	struct timeval	*last_eat;
	struct timeval	*time;
	struct s_data	*next;
	int				test;
}					t_data;

void				ft_thread(t_data *data);
void				ft_free(t_data *data);
void				ft_printf(char *s, t_data *data);
void				ft_sleep(int i);
int					ft_atoi(char *str);
t_data				*ft_initialize(int argc, char **argv, int *die);
long unsigned int	ft_time(struct timeval *time);

#endif