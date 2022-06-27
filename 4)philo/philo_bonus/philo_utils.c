/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:49:20 by doreshev          #+#    #+#             */
/*   Updated: 2022/06/24 13:06:20 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free(t_data *data)
{
	t_data	*tmp;

	tmp = data;
	while (tmp)
	{
		kill(tmp->pid, SIGKILL);
		tmp = tmp->next;
	}
	free(data->time);
	sem_close(data->fork);
	while (data)
	{
		free(data->tid);
		free(data->last_eat);
		tmp = data;
		data = data->next;
		free(tmp);
	}
	sem_unlink("/sem1");
	sem_unlink("/sem2");
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
	struct timeval		*tmp;

	tmp = malloc(sizeof(struct timeval) * 1);
	if (!tmp)
		return (-1);
	if (gettimeofday(tmp, 0) == -1)
		return (-1);
	i = (tmp->tv_sec - time->tv_sec) * 1000;
	i += (tmp->tv_usec - time->tv_usec) / 1000;
	free(tmp);
	return (i);
}

void	ft_printf(char *s, t_data *data)
{
	long int	i;

	i = ft_time(data->time);
	if (i < 0 || *data->die)
		return ;
	sem_wait(data->in);
	printf("%lums %i %s\n", i, data->phn, s);
	sem_post(data->in);
}

void	ft_sleep(int i)
{
	struct timeval	*tmp;
	int				j;

	tmp = malloc(sizeof(struct timeval) * 1);
	if (!tmp)
		return ;
	if (gettimeofday(tmp, 0) == -1)
		return ;
	j = 0;
	while (j < i)
	{
		usleep(50);
		j = ft_time(tmp);
	}
	free(tmp);
}
