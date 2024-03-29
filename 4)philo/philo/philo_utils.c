/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:49:20 by doreshev          #+#    #+#             */
/*   Updated: 2022/08/18 17:36:32 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_data *data)
{
	t_data	*tmp;

	pthread_mutex_unlock(data->in);
	pthread_mutex_destroy(data->in);
	free(data->in);
	pthread_mutex_destroy(data->done_eat);
	free(data->done_eat);
	free(data->time);
	while (data)
	{
		pthread_join(*data->tid, 0);
		tmp = data;
		pthread_mutex_destroy(data->fork_r);
		free(data->fork_r);
		free(data->tid);
		free(data->last_eat);
		data = data->next;
		free(tmp);
	}
}

int	ft_atoi(char *str)
{
	int	mod;
	int	i;

	i = 0;
	mod = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
		|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		mod = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	if (*str < 48 || *str > 57)
		return (-1);
	while (*str > 47 && *str < 58)
	{
		i = i * 10 + (*str - 48);
		str++;
	}
	if (*str && (*str < 48 || *str > 57))
		return (-1);
	return (mod * i);
}

long unsigned int	ft_time(struct timeval *time)
{
	long unsigned int	i;
	struct timeval		tmp;

	if (gettimeofday(&tmp, 0) == -1)
		return (-1);
	i = (tmp.tv_sec - time->tv_sec) * 1000;
	i += (tmp.tv_usec - time->tv_usec) / 1000;
	return (i);
}

void	ft_printf(char *s, t_data *data)
{
	long int	i;

	pthread_mutex_lock(data->in);
	i = ft_time(data->time);
	if (*data->die)
	{
		pthread_mutex_unlock(data->in);
		return ;
	}
	printf("%lums %i %s\n", i, data->phn, s);
	pthread_mutex_unlock(data->in);
}

void	ft_sleep(int i)
{
	struct timeval	tmp;
	int				j;

	if (gettimeofday(&tmp, 0) == -1)
		return ;
	j = 0;
	while (j < i)
	{
		usleep(200);
		j = ft_time(&tmp);
	}
}
