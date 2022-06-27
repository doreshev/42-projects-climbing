/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 20:15:48 by doreshev          #+#    #+#             */
/*   Updated: 2022/06/24 13:23:04 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_thread_sub(t_data *data)
{
	if (*data->die)
		return ;
	pthread_mutex_lock(data->fork_r);
	ft_printf("has taken a fork", data);
	if (*data->die)
	{
		pthread_mutex_unlock(data->fork_r);
		return ;
	}
	pthread_mutex_lock(data->fork_l);
	ft_printf("has taken a fork", data);
	if (gettimeofday(data->last_eat, 0))
		return ;
	if (*data->die)
	{
		pthread_mutex_unlock(data->fork_l);
		pthread_mutex_unlock(data->fork_r);
		return ;
	}
	ft_printf("is eating", data);
	ft_sleep(data->t2e);
	pthread_mutex_unlock(data->fork_l);
	pthread_mutex_unlock(data->fork_r);
}

void	ft_thread_t2em(t_data *data)
{
	while (data->t2em)
	{
		ft_thread_sub(data);
		if (*data->die)
			return ;
		data->t2em--;
		if (data->t2em == 0)
		{
			pthread_mutex_lock(data->done_eat);
			*data->done += 1;
			pthread_mutex_unlock(data->done_eat);
			return ;
		}
		ft_printf("is sleeping", data);
		ft_sleep(data->t2s);
		ft_printf("is thinking", data);
	}
}

void	ft_thread_infinite(t_data *data)
{
	while (*data->die == 0)
	{
		ft_thread_sub(data);
		ft_printf("is sleeping", data);
		if (*data->die)
			return ;
		ft_sleep(data->t2s);
		ft_printf("is thinking", data);
	}
}

void	ft_thread(t_data *data)
{
	if (data->phn % 2 != 0)
		usleep(data->t2e * 100);
	if (data->t2em)
		ft_thread_t2em(data);
	else
		ft_thread_infinite(data);
}
