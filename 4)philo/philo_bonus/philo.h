/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:11:13 by doreshev          #+#    #+#             */
/*   Updated: 2022/06/20 19:41:26 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <semaphore.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <signal.h>
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
	sem_t			*fork;
	sem_t			*in;
	pid_t			pid;
	pthread_t		*tid;
	struct timeval	*last_eat;
	struct timeval	*time;
	struct s_data	*next;
}					t_data;

void				ft_child_process(t_data *data);
void				ft_free(t_data *data);
void				ft_printf(char *s, t_data *data);
void				ft_sleep(int i);
int					ft_atoi(char *str);
t_data				*ft_initialize(int argc, char **argv);
long unsigned int	ft_time(struct timeval *time);

#endif