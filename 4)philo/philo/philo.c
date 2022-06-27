/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doreshev <doreshev@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:29:29 by doreshev          #+#    #+#             */
/*   Updated: 2022/06/24 13:13:36 by doreshev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sub_dead(t_data *data)
{
	t_data				*tmp;
	int					j;
	long unsigned int	i;

	tmp = data;
	while (*data->done < data->tot_ph)
	{
		j = ft_time(data->last_eat);
		if (j >= data->t2d)
		{
			*data->die = 1;
			pthread_mutex_lock(data->in);
			i = ft_time(data->time);
			printf("%lums %i died!\n", i, data->phn);
			return ;
		}
		data = data->next;
		if (data == NULL)
			data = tmp;
	}
}

void	ft_thread_create(t_data *data, int	*done)
{
	t_data				*tmp;
	struct timeval		*time1;

	time1 = malloc(sizeof(struct timeval) * 1);
	if (!time1 || gettimeofday(time1, 0) == -1)
		return ;
	tmp = data;
	while (tmp)
	{
		tmp->done = done;
		tmp->time = time1;
		tmp->last_eat = malloc(sizeof(struct timeval) * 1);
		if (!tmp->last_eat || gettimeofday(tmp->last_eat, 0) == -1)
			return ;
		tmp->tid = malloc(sizeof(pthread_t) * 1);
		if (!tmp->tid)
			return ;
		if (pthread_create(tmp->tid, 0, (void *)&ft_thread, (void *)tmp))
			return ;
		tmp = tmp->next;
	}
	ft_sub_dead(data);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	int		die;
	int		done;

	if (argc == 5 || argc == 6)
	{
		die = 0;
		done = 0;
		data = ft_initialize(argc, argv, &die);
		if (data == NULL)
			return (1);
		ft_thread_create(data, &done);
		ft_free(data);
	}
	else
		printf("Wrong input parameters!\n");
	return (0);
}
