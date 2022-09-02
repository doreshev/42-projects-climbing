/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:15:48 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/23 17:37:26 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_dead(t_data *data)
{
	int					j;
	long unsigned int	i;

	while (*data->die == 0)
	{
		j = ft_time(data->last_eat);
		if (j >= data->t2d)
		{
			*data->die = 1;
			i = ft_time(data->time);
			sem_wait(data->in);
			printf("%lums %i died!\n", i, data->phn);
			sem_close(data->in);
			return ;
		}
		usleep(200);
	}
}

void	ft_process_sub(t_data *data)
{
	if (*data->die)
		return ;
	sem_wait(data->fork);
	ft_printf("has taken a fork", data);
	if (*data->die)
	{
		sem_post(data->fork);
		return ;
	}
	sem_wait(data->fork);
	ft_printf("has taken a fork", data);
	if (gettimeofday(data->last_eat, 0))
		return ;
	if (*data->die)
	{
		sem_post(data->fork);
		sem_post(data->fork);
		return ;
	}
	ft_printf("is eating", data);
	ft_sleep(data->t2e);
	sem_post(data->fork);
	sem_post(data->fork);
}

void	ft_process_t2em(t_data *data)
{
	while (data->t2em)
	{
		ft_process_sub(data);
		if (*data->die)
			return ;
		data->t2em--;
		if (data->t2em == 0)
		{
			pthread_detach(*data->tid);
			exit(0);
		}
		ft_printf("is sleeping", data);
		ft_sleep(data->t2s);
		ft_printf("is thinking", data);
	}
}

void	ft_process_infinite(t_data *data)
{
	while (*data->die == 0)
	{
		ft_process_sub(data);
		if (*data->die)
			return ;
		ft_printf("is sleeping", data);
		ft_sleep(data->t2s);
		ft_printf("is thinking", data);
	}
}

void	ft_child_process(t_data *data)
{
	int	die;

	die = 0;
	data->die = &die;
	if (data->phn % 2 != 0)
		usleep(200);
	if (pthread_create(data->tid, 0, (void *)&ft_dead, (void *)data))
		exit(1);
	if (data->t2em)
		ft_process_t2em(data);
	else
		ft_process_infinite(data);
	pthread_join(*data->tid, 0);
	exit(1);
}
